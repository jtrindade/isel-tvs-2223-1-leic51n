.PHONY: all clean

all: shmem-srv shmem-cli shmem-clean

shmem-srv: test_shmem_srv.c shmem.c shmem.h
	gcc -Wall -o shmem-srv test_shmem_srv.c shmem.c

shmem-cli: test_shmem_cli.c shmem.c shmem.h
	gcc -Wall -o shmem-cli test_shmem_cli.c shmem.c

shmem-clean: test_shmem_clean.c shmem.c shmem.h
	gcc -Wall -o shmem-clean test_shmem_clean.c shmem.c

clean:
	rm -f shmem-*

