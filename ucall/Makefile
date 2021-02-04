CFLAGS= -nostdlib

all: ucall.elf

%.elf: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ucall.elf
.PHONY: all clean
