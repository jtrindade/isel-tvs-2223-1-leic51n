.PHONY: all clean

all: echo-srv echo-cli echo-trm

echo-srv: echo-server.c echo-service.h ../02-memchannel/memchannel.c ../02-memchannel/memchannel.h ../01-shmem/shmem.c ../01-shmem/shmem.h
	gcc -Wall -I../01-shmem -I../02-memchannel -o echo-srv echo-server.c ../02-memchannel/memchannel.c ../01-shmem/shmem.c

echo-cli: echo-client.c echo-service.h ../02-memchannel/memchannel.c ../02-memchannel/memchannel.h ../01-shmem/shmem.c ../01-shmem/shmem.h
	gcc -Wall -I../01-shmem -I../02-memchannel -o echo-cli echo-client.c ../02-memchannel/memchannel.c ../01-shmem/shmem.c

echo-trm: echo-term.c echo-service.h ../02-memchannel/memchannel.c ../02-memchannel/memchannel.h ../01-shmem/shmem.c ../01-shmem/shmem.h
	gcc -Wall -I../01-shmem -I../02-memchannel -o echo-trm echo-term.c ../02-memchannel/memchannel.c ../01-shmem/shmem.c

clean:
	rm -f echo-srv echo-cli echo-trm

