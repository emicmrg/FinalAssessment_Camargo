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

# Add your Source files to this variable
MSP432_S = main.c \
		memory.c \
        interrupts_msp432p401r_gcc.c \
		startup_msp432p401r_gcc.c \
		system_msp432p401r.c
HOST_S = src/main.c \
        src/memory.c \
		src/data.c \
		src/course1.c \
		src/stats.c

# Add your include paths to this variable
MSP432_I = -I include/CMSIS \
           -I include/common \
		   -I include/msp432
HOST_I = -I include/common