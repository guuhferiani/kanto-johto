
MAKEFLAGS += --no-print-directory

TOOLDIRS := $(patsubst %/,%,$(filter-out tools/agbcc/ tools/binutils/,$(wildcard tools/*/)))

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@
