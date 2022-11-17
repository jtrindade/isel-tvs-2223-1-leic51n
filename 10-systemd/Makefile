.PHONY: all clean

all: echod echod-cli

echod: echod.c /usr/include/systemd/sd-daemon.h
	gcc -Wall -o echod echod.c -lsystemd

echod-cli: echod-cli.c
	gcc -Wall -o echod-cli echod-cli.c

/usr/include/systemd/sd-daemon.h:
	sudo apt install libsystemd-dev

clean:
	rm -f echod echod-cli

