#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int value = 88;

int main() {
	
	puts("prog4 running");
	
	printf("PARENT: %d (from %d)\n", getpid(), getppid());
	
	puts("forking...");
	
	pid_t pid = fork();
	
	if (pid == 0) {
		printf("CHILD: %d (from %d)\n", getpid(), getppid());
		printf("CHILD: new child of %d\n", getppid());
		value += 1000;
	} else {
		printf("PARENT: %d (from %d)\n", getpid(), getppid());
		printf("PARENT: new child %d\n", pid);
	}
	
	printf("[%d] working...\n", getpid());

	// Both parent and child run this code at the same time.
	// Although the memory address of 'value' is the same in both
	// processes, 'value' holds independent values in each process.
	for (int i = 0; i < 10; ++i) {
		printf("[%d] value at %p is %d\n", getpid(), &value, value);
		value += 1;
		sleep(1);
	}
	
	if (pid == 0) {
		puts("DONE");
	} else {
		int res;
		waitpid(pid, &res, 0);
		
		if (WIFEXITED(res)) {
			printf("PARENT: child terminated with %d\n", WEXITSTATUS(res));
		} else {
			printf("PARENT: child terminated\n");
		}
	}
}
