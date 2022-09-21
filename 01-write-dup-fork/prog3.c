#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	puts("prog3 running");
	
	printf("PARENT: %d (from %d)\n", getpid(), getppid());
	
	puts("forking...");
	
	int res = fork();
	
	if (res == 0) {
		printf("CHILD: %d (from %d)\n", getpid(), getppid());
	} else {
		printf("PARENT: %d (from %d)\n", getpid(), getppid());
		wait(NULL);
	}
	
	puts("THE END");
}
