#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	
	puts("prog3 running");
	
	printf("PARENT: %d (from %d)\n", getpid(), getppid());
	
	puts("forking...");
	
	pid_t pid = fork();
	
	if (pid == 0) {
		printf("CHILD: %d (from %d)\n", getpid(), getppid());
		printf("CHILD: new child of %d\n", getppid());
		return 123;
	} else {
		printf("PARENT: %d (from %d)\n", getpid(), getppid());
		printf("PARENT: new child %d\n", pid);

		int res;
		waitpid(pid, &res, 0);
		
		if (WIFEXITED(res)) {
			printf("PARENT: child terminated with %d\n", WEXITSTATUS(res));
		} else {
			printf("PARENT: child terminated\n");
		}
	}
}
