#include <unistd.h>
#include <stdio.h>
#include <errno.h>

// RUN:
//   ./prog1
//   ./prog1 3> abc.txt
//
int main() {
	write(1, "prog1 running\n", 14);
	
	if (write(3, "hello, world\n", 13)==-1) {
		perror("write failed");
	} else {
		write(1, "prog1 success\n", 14);
	}

	return 0; 
}
