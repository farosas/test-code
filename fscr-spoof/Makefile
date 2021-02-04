ASFLAGS= -mbig -mpower9
LDFLAGS= -T lds
OBJFLAGS= -O binary -S

OBJCOPY=objcopy

all: fscr.bin fscr.elf

%.bin: %.elf
	$(OBJCOPY) $< $(OBJFLAGS) $@

%.elf: %.o
	$(LD) $< -o $@ $(LDFLAGS)

clean:
	rm -f fscr.bin fscr.elf
.PHONY: all clean
