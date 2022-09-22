#include <unistd.h>
#include <stdio.h>
#include <errno.h>

// RUN:
//   ./prog1
//   ./prog1 88> abc.txt
//
int main() {
	write(1, "prog2b running\n", 15);
	
	int nfd = dup2(1, 88);

	if (write(nfd, "hello, world 1\n", 15)==-1) {
		perror("write to nfd failed");
	} else {
		puts("write to nfd succeded");
	}
	
	if (write(88, "hello, world 2\n", 15)==-1) {
		perror("write to 88 failed");
	} else {
		puts("write to 88 succeded");
	}

	return 0; 
}
