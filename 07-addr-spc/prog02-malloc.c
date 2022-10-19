// Large allocations increase the valid address space.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf(":: RUNNING %d ::\n", getpid());
	
	getchar();
	
	void  * ptr = malloc(4*1024*1024);
	
	getchar();
	
	free (ptr);

	return 0;
}
