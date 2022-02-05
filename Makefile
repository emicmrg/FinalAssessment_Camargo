#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
#
# Use: make [File].extension PLATFORM=HOST/MSP432
#
# This command will create the file type you wish for the selected platform
#
#------------------------------------------------------------------------------
#
# Use: make build PLATFORM=HOST/MSP432
#
# This command will compile and link into a final executable
#
#------------------------------------------------------------------------------
#
# Use: make compile-all PLATFORM=HOST/MSP432
#
# This command will compile but do not link
#
#------------------------------------------------------------------------------
#
# Use: make clean PLATFORM=HOST/MSP432
#
# This command will remove all compiled objects, preprocessed output, assembly outputs,
# executable and build files
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = $(shell)
TARGET = c1m2

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -Wl,-T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) \
	         -m$(ARCH) \
			 -march=armv7e-m \
			 -mfloat-abi=hard \
			 -mfpu=fpv4-sp-d16 \
			 --specs=$(SPECS) \
			 -g \
			 -std=c99 \
			 -O0 \
			 -Wall \
			 -Werror
	SOURCES = $(MSP432_S)
	INCLUDES = $(MSP432_I)
	SIZE = arm-none-eabi-size
	OBJDUMP_TOOL = arm-none-eabi-objdump
endif

ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -g -std=c99 -O0 -Wall -Werror
	CPPFLAGS = -M -MF
	SOURCES = $(HOST_S)
	INCLUDES = $(HOST_I)
	SIZE = size
	OBJDUMP_TOOL = objdump
endif

OBJS:= $(SOURCES:.c=.o)
ASMF:= $(SOURCES:.c=.asm)
LNKF:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)

%.i : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -E -o $@ $<

%.asm : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $< -S

%.asm : %.out
	$(OBJDUMP_TOOL) --disassemble $< > $@

%.o : %.c
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -c $<

.PHONY: compile-all
compile-all:
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -c $(SOURCES)

.PHONY: build
build:
	$(CC) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) -Bx $(TARGET).out
	$(SIZE) -Btd $(TARGET).out

.PHONY: clean
clean:
	rm -f *.i *.d *.map *.s *.asm *.out *.o 