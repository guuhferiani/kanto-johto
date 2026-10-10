#!/usr/bin/env python3
"""
Upload de ROM Pokemon Kanto-Johto para o Google Drive.
Compatível com Python 3.10+ no Windows/Linux.
"""

import os
import sys
import argparse
from pathlib import Path

# Garante saida imediata (unbuffered) no terminal e nos arquivos de log
try:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(line_buffering=True)
    if hasattr(sys.stderr, "reconfigure"):
        sys.stderr.reconfigure(line_buffering=True)
except Exception:
    pass

try:
    from google.auth.transport.requests import Request
    from google.oauth2.credentials import Credentials
    from google_auth_oauthlib.flow import InstalledAppFlow
    from googleapiclient.discovery import build
    from googleapiclient.http import MediaFileUpload
except ImportError:
    print("[ERRO] Bibliotecas do Google Drive não instaladas.", flush=True)
    print("Execute: pip install google-api-python-client google-auth-httplib2 google-auth-oauthlib", flush=True)
    sys.exit(1)

SCOPES = ["https://www.googleapis.com/auth/drive.file"]
DEFAULT_FOLDER_NAME = "Pokemon_Kanto_Johto"

ROOT_DIR = Path(__file__).resolve().parent.parent
SCRIPTS_DIR = Path(__file__).resolve().parent

def find_credentials_file() -> Path | None:
    candidates = [
        SCRIPTS_DIR / "credentials.json",
        ROOT_DIR / "credentials.json",
        Path("credentials.json"),
    ]
    for c in candidates:
        if c.exists():
            return c
    return None

def find_token_file() -> Path:
    token_in_scripts = SCRIPTS_DIR / "token.json"
    if token_in_scripts.exists():
        return token_in_scripts
    return ROOT_DIR / "token.json"

def print_setup_instructions():
    print("=" * 65)
    print("   COMO OBTER O ARQUIVO 'credentials.json' DO GOOGLE DRIVE   ")
    print("=" * 65)
    print("""
1. Acesse o Google Cloud Console:
   https://console.cloud.google.com/

2. Crie um projeto novo (ex: 'Pokemon-GBA-Sync').

3. No menu lateral, vá em:
   'APIs e Serviços' -> 'Biblioteca' (Library)
   Procure por 'Google Drive API' e clique em 'Ativar' (Enable).

4. Vá em 'APIs e Serviços' -> 'Tela de consentimento OAuth':
   - Tipo de usuário: 'Externo' (External)
   - Nome do app: 'Pokemon GBA Sync'
   - Preencha seu email e salve até concluir.
   - Em 'Usuários de teste' (Test users), adicione o seu próprio email do Google!

5. Vá em 'APIs e Serviços' -> 'Credenciais':
   - Clique em '+ Criar Credenciais' -> 'ID do cliente OAuth'
   - Tipo de aplicativo: 'Aplicativo para computador' (Desktop App)
   - Clique em 'Criar'.

6. Clique no botão de download para baixar o arquivo JSON.
7. Renomeie o arquivo baixado para 'credentials.json' e coloque na pasta:
   {scripts_dir}
   ou na raiz do projeto:
   {root_dir}

Depois é só rodar este script novamente!
    """.format(scripts_dir=SCRIPTS_DIR, root_dir=ROOT_DIR))
    print("=" * 65)

def get_drive_service():
    creds_file = find_credentials_file()
    token_file = find_token_file()
    creds = None

    if token_file.exists():
        creds = Credentials.from_authorized_user_file(str(token_file), SCOPES)

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            print("[INFO] Atualizando token expirado...")
            try:
                creds.refresh(Request())
                with open(token_file, "w", encoding="utf-8") as f:
                    f.write(creds.to_json())
            except Exception as e:
                print(f"[AVISO] Falha ao atualizar token: {e}. Reautenticando...")
                creds = None

        if not creds:
            if not creds_file:
                print("\n[ERRO] Arquivo 'credentials.json' não encontrado!")
                print_setup_instructions()
                sys.exit(1)

            print(f"[INFO] Usando credenciais de: {creds_file}", flush=True)
            print("[INFO] Iniciando servidor local para autenticacao...", flush=True)
            flow = InstalledAppFlow.from_client_secrets_file(str(creds_file), SCOPES)
            creds = flow.run_local_server(
                port=0,
                open_browser=True,
                authorization_prompt_message="\n[AÇÃO NECESSÁRIA] Acesse o link abaixo no seu navegador para autorizar:\n\n{url}\n\n"
            )

            # Salva token para as próximas execuções
            save_path = SCRIPTS_DIR / "token.json"
            with open(save_path, "w", encoding="utf-8") as token:
                token.write(creds.to_json())
            print(f"[SUCESSO] Token salvo com sucesso em: {save_path}", flush=True)

    return build("drive", "v3", credentials=creds)

def get_or_create_folder(service, folder_name: str) -> str:
    query = f"name = '{folder_name}' and mimeType = 'application/vnd.google-apps.folder' and trashed = false"
    response = service.files().list(q=query, spaces='drive', fields='files(id, name)').execute()
    files = response.get('files', [])

    if files:
        folder_id = files[0]['id']
        print(f"[DRIVE] Pasta encontrada: '{folder_name}' (ID: {folder_id})")
        return folder_id

    file_metadata = {
        'name': folder_name,
        'mimeType': 'application/vnd.google-apps.folder'
    }
    folder = service.files().create(body=file_metadata, fields='id').execute()
    folder_id = folder.get('id')
    print(f"[DRIVE] Nova pasta criada: '{folder_name}' (ID: {folder_id})")
    return folder_id

def find_file_in_folder(service, folder_id: str, file_name: str) -> str | None:
    query = f"'{folder_id}' in parents and name = '{file_name}' and trashed = false"
    response = service.files().list(q=query, spaces='drive', fields='files(id, name)').execute()
    files = response.get('files', [])
    if files:
        return files[0]['id']
    return None

def upload_rom(file_path: Path, folder_name: str = DEFAULT_FOLDER_NAME):
    if not file_path.exists():
        print(f"[ERRO] Arquivo não encontrado: {file_path}")
        sys.exit(1)

    file_size_mb = file_path.stat().st_size / (1024 * 1024)
    print(f"[LOCAL] Arquivo pronto: {file_path.name} ({file_size_mb:.2f} MB)")

    service = get_drive_service()
    folder_id = get_or_create_folder(service, folder_name)

    existing_file_id = find_file_in_folder(service, folder_id, file_path.name)
    media = MediaFileUpload(str(file_path), mimetype='application/octet-stream', resumable=True)

    if existing_file_id:
        print(f"[DRIVE] Substituindo arquivo existente '{file_path.name}'...")
        updated_file = service.files().update(
            fileId=existing_file_id,
            media_body=media,
            fields='id, name, webViewLink, modifiedTime'
        ).execute()
        print(f"[SUCESSO] Arquivo atualizado no Google Drive!")
        print(f"         Nome: {updated_file.get('name')}")
        print(f"         Link: {updated_file.get('webViewLink')}")
        print(f"         Modificado em: {updated_file.get('modifiedTime')}")
    else:
        print(f"[DRIVE] Fazendo upload de novo arquivo '{file_path.name}'...")
        file_metadata = {
            'name': file_path.name,
            'parents': [folder_id]
        }
        uploaded_file = service.files().create(
            body=file_metadata,
            media_body=media,
            fields='id, name, webViewLink'
        ).execute()
        print(f"[SUCESSO] Arquivo enviado para o Google Drive!")
        print(f"         Nome: {uploaded_file.get('name')}")
        print(f"         Link: {uploaded_file.get('webViewLink')}")

def main():
    parser = argparse.ArgumentParser(description="Upload de ROM para o Google Drive")
    parser.add_argument("--file", "-f", type=str, help="Caminho do arquivo .gba a ser enviado")
    parser.add_argument("--folder", type=str, default=DEFAULT_FOLDER_NAME, help="Nome da pasta no Google Drive")
    parser.add_argument("--setup", action="store_true", help="Apenas configurar autenticação inicial")
    args = parser.parse_args()

    if args.setup:
        print("[SETUP] Verificando configuração do Google Drive...")
        get_drive_service()
        print("[SETUP] Autenticação configurada com sucesso!")
        return

    # Procura a ROM padrão se não especificada
    target_file = None
    if args.file:
        target_file = Path(args.file)
    else:
        candidates = [
            ROOT_DIR / "Pokemon_Kanto_Johto.gba",
            ROOT_DIR / "pokeClassic.gba",
        ]
        for c in candidates:
            if c.exists():
                target_file = c
                break

    if not target_file:
        print("[ERRO] Nenhuma ROM .gba encontrada na raiz do projeto!")
        print("Especifique o arquivo com: python scripts/upload_to_drive.py --file caminho/arquivo.gba")
        sys.exit(1)

    upload_rom(target_file, args.folder)

if __name__ == "__main__":
    main()
