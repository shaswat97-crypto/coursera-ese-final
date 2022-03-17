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
# <Make file capabale of compiling for different targets such as host linux and target cpu>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <supported targets are linux and bare metal>
#
# Platform Overrides:
#      <platform overrides are defined as PLATFORM=HOST & PLATFORM=MSP432>
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM =
Basename = c1m2
TARGET = $(Basename).out

ifeq ($(PLATFORM),HOST)

	# Compiler Flags and Defines
CC = gcc
LDFLAGS = -Wl,-Map=$(Basename).map
CFLAGS = -Wall -Werror -O0 -g -std=c99
CPPFLAGS = -E
	#pattern matching target for binary(object) files
%.o : %.c
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -c -MD $< -o $@
	
%.i : %.c
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -MD $< -o $@

%.asm : %.c
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -S -MD $< -o $@

.PHONY : compile-all
compile-all : $(aSOURCES:.c=.o)
%.o : $(aSOURCES)
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -c -MD $< -o $@

.PHONY : Build
Build : $(aSOURCES)
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $(aSOURCES) -MD $(LDFLAGS) -o $(TARGET)

else

#Target
Basename = c1m2
Target = $(Basename).out

# Architectures Specific Flags
LINKER_FILE = -Tmsp432p401r.lds 
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(Basename).map
CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -Wall -g -std=c99 -Werror -O0

#Pattern matching  target
%.i : %.c
	$(CC) $(LINKER_FILE) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -MD -E $< -o $@
%.asm : %.c
	$(CC) $(LINKER_FILE) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -MD -S $< -o $@
%.o : %.c
	$(CC) $(LINKER_FILE) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -MD -c $< -o $@

.PHONY: compile-all
compile-all : $(aSOURCES:.c=.o)
%.o : $(aSOURCES)
	$(CC) $(LINKER_FILE) -D$(PLATFORM) $(INCLUDES) $(CFLAGS) -MD -c $< -o $@

.PHONY: Build
Build : $(aSOURCES)
	$(CC) $(INCLUDES) $(LINKER_FILE) -D$(PLATFORM) $(CFLAGS) $(LDFLAGS) -MD $(aSOURCES) -o $(Target)
endif

.PHONY : clean
clean :
	rm -f *.o *.i *.asm *.map *.out *.d
