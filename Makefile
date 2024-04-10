# Project Name (generate executable with this name)
TARGET   = xTetris

CC       = gcc
# compiling flags here
CFLAGS   = -ansi -pedantic -O2 -Wall -Wextra -lm -D _DEFAULT_SOURCE

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -pedantic -O2 -Wall -Wextra -lm

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = src
BINDIR   = src

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
