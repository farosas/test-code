ASFLAGS= -mbig -mpower9
LDFLAGS= -T lds
OBJFLAGS= -O binary -S

OBJCOPY=objcopy

all: slof.bin slof.elf

%.bin: %.elf
	$(OBJCOPY) $< $(OBJFLAGS) $@

%.elf: %.o
	$(LD) $< -o $@ $(LDFLAGS)

clean:
	rm -f slof.bin slof.elf
.PHONY: all clean
