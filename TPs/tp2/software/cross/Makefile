ifndef CROSS_COMPILE
CROSS_COMPILE=riscv64-unknown-elf-
endif

CROSS_COMPILE=riscv64-elf-

# Optimization: do not use -O3 as it generates sb/sh/lh/lhu that the *bus*
# is not able to handle yet
# Also, change that so that we can use compressed instructions!
TARGET_CC = $(CROSS_COMPILE)gcc -g -O2 -march=rv32g -mabi=ilp32
TARGET_LD = $(CROSS_COMPILE)ld -m elf32lriscv
TARGET_OBJDUMP = $(CROSS_COMPILE)objdump
TARGET_READELF = $(CROSS_COMPILE)readelf
HOST_CC = gcc
HOST_LD = ld
HOST_OBJDUMP = objdump
HOST_READELF = readelf

INCLUDE = -I. -I../..

OBJS = main.o trap.o it.o boot.o
EXEC = a.out


all: a.out dump.dis sections.txt

# Disassembly of the generated executable.
dump.dis: $(EXEC)
	$(TARGET_OBJDUMP) --disassembler-options=no-aliases,numeric -d $< > $@

# Summary of the sections and their size.
sections.txt: $(EXEC)
	$(TARGET_READELF) -S $< > $@


$(EXEC): $(OBJS)
# TODO: use $(TARGET_LD), and use the -T option to point to linker script ldscript
	$(TARGET_LD) -T ldscript $(OBJS) -o $@

main.o: ../main.c ../../address_map.h # TODO: dependencies
# TODO: compile with target C compiler
	$(TARGET_CC) $(INCLUDE) -g -c $< -o $@
	
trap.o: trap.c ../../address_map.h # TODO: dependencies
# TODO: compile with target C compiler
	$(TARGET_CC) $(INCLUDE) -g -c $< -o $@


%.o: %.s
	$(TARGET_CC) -c $< -o $@

.PHONY: clean realclean
clean:
	-$(RM) $(OBJS) $(EXEC) dump.dis sections.txt

realclean: clean
	-$(RM) *~
