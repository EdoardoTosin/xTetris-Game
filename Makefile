# Project Name (generate executable with this name)
TARGET   = xTetris

# Compiler and Linker
CC       = gcc

# Flags for compiling and linking
CFLAGS   = -ansi -pedantic -O3 -Wall -Wextra -D _DEFAULT_SOURCE
LFLAGS   = -lm

# Directories for source, object, binary, and docs
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
DOCDIR   = docs

# Gather sources and objects
SOURCES  := $(wildcard $(SRCDIR)/*.c)
OBJECTS  := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Default target - builds all
all: $(BINDIR)/$(TARGET)

# Build executable
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@$(CC) $^ $(LFLAGS) -o $@
	@echo "Linking complete! Executable: $@"

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< -> $@"

# Run the executable
.PHONY: run
run: all
	@echo "Running $(TARGET)..."
	@./$(BINDIR)/$(TARGET)

# Clean up object files and binaries
.PHONY: clean
clean:
	@$(RM) -r $(OBJDIR) $(BINDIR)
	@echo "Cleanup complete! Removed $(OBJDIR) and $(BINDIR) directories."

# Clean up documentation files
.PHONY: clean-docs
clean-docs:
	@$(RM) -r $(DOCDIR)
	@echo "Documentation cleaned up from $(DOCDIR) directory."

# Generate documentation (using Doxygen as an example)
.PHONY: doc
doc:
	@mkdir -p $(DOCDIR)
	@doxygen Doxyfile
	@echo "Documentation generated in $(DOCDIR) directory."

# Install the executable to a system directory (e.g., /usr/local/bin)
.PHONY: install
install: all
	@install -m 0755 $(BINDIR)/$(TARGET) /usr/local/bin
	@echo "Installed $(TARGET) to /usr/local/bin."

# Display help information
.PHONY: help
help:
	@echo "Available make targets:"
	@echo "  all         - Build the executable"
	@echo "  clean       - Remove object and binary files"
	@echo "  clean-docs  - Remove generated documentation"
	@echo "  run         - Run the executable"
	@echo "  doc         - Generate documentation"
	@echo "  install     - Install the executable to /usr/local/bin"
	@echo "  help        - Display this help information"

# Full rebuild
.PHONY: rebuild
rebuild: clean all
	@echo "Rebuild complete!"
