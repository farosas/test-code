all: hooks.so

CFLAGS:=-Wall -fPIC -shared -ldl

%.so: %.c
	$(CC) $(CFLAGS) $< -o $@
