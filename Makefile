INC_DIR =./include

DEVICE = msp430fr4133

CC = msp430-elf-gcc

CFLAGS = -I . -I$(INC_DIR) -mmcu=$(DEVICE) -g -mhwmult=auto
LFLAGS = -L . -L$(INC_DIR)

TARGET = blink.elf

DRIVER := tilib

# Compilation
all: $(TARGET)

%.elf : %.c
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

# upload to board
install : $(TARGET)
	mspdebug $(DRIVER) "prog $<" --allow-fw-update

clean:
	rm -f *.o *.elf
