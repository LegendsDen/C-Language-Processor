# Makefile for assembling, linking, and running a 32-bit NASM program on a 64-bit machine

# Program name (without extension)
TARGET = 220101096_set_A8

# NASM assembler and flags
ASM = nasm
ASM_FLAGS = -f elf32

# Linker and flags for 32-bit executable
LD = ld
LD_FLAGS = -m elf_i386

# Default target
all: $(TARGET)

# Assemble .asm file into a .o object file
$(TARGET).o: $(TARGET).asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

# Link the object file into an executable
$(TARGET): $(TARGET).o
	$(LD) $(LD_FLAGS) -o $@ $<

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET) $(TARGET).o
