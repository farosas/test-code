CFLAGS= -nostdlib

all: tar.elf

%.elf: %.s
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f tar.elf
.PHONY: all clean
