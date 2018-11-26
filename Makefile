# N.B. PKGPATH variable must be set first
# Install with make_build.sh script which automatically sets
# Files
EXEC := main
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))
# Options
CC := gcc
CGLAGS := -g
IDFLAGS := -I$(PKGPATH/include)
LDFLAGS := -L$(PKGPATH/lib)
LDLIBS := -lgrvy
DLFLAGS := -Wl, -rpath=$(PKPATH/lib) -l:libgrvy-0.34.so
# Rules
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^ $(DFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(IDFLAGS) -c $<
# Phony targets
.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat:
	$(RM) *~.*~
echo:
	@echo $(OBJ)
