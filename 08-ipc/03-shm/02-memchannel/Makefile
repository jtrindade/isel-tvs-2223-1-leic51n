.PHONY: all clean

all: memch-srv memch-cli

memch-srv: test_memchannel_srv.c memchannel.c memchannel.h ../01-shmem/shmem.c ../01-shmem/shmem.h
	gcc -Wall -I../01-shmem -o memch-srv test_memchannel_srv.c memchannel.c ../01-shmem/shmem.c

memch-cli: test_memchannel_cli.c memchannel.c memchannel.h ../01-shmem/shmem.c ../01-shmem/shmem.h
	gcc -Wall -I../01-shmem -o memch-cli test_memchannel_cli.c memchannel.c ../01-shmem/shmem.c

clean:
	rm -f memch-*

