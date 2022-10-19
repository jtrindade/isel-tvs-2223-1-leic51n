all: prog01 prog02 prog03-mylib.so prog03 prog04 prog05

prog01: prog01-base-image.c
	gcc -Wall -o prog01 prog01-base-image.c       	

prog02: prog02-malloc.c
	gcc -Wall -o prog02 prog02-malloc.c       	

prog03-mylib.so: prog03-shared-object-lib.c
	gcc -Wall -fPIC -shared -o prog03-mylib.so prog03-shared-object-lib.c

prog03: prog03-mylib.so prog03-shared-object-prog.c
	gcc -Wall -o prog03 prog03-shared-object-prog.c       	

prog04: prog04-mmap-file.c
	gcc -Wall -o prog04 prog04-mmap-file.c       	

prog05: prog05-mmap-anon.c
	gcc -Wall -o prog05 prog05-mmap-anon.c       	

clean:
	rm -f prog01 prog02 prog03-mylib.so prog03 prog04 prog05

