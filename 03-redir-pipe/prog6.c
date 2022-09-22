#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	
	puts("prog6 running");
	
	printf("PARENT: %d (from %d)\n", getpid(), getppid());
	
	puts("forking...");
	
	pid_t pid = fork();
	
	if (pid == 0) {
		printf("CHILD: %d (from %d)\n", getpid(), getppid());
		printf("CHILD: new child of %d\n", getppid());
		
		// Opens (and creates if needed) a file 'out.txt'
		int ofd = open("out.txt", O_CREAT|O_WRONLY, 0640);
		if (ofd == -1) {
			perror("open out.txt failed");
			exit(1);
		}
		
		// Replaces standard output with 'out.txt' descriptor 
		dup2(ofd, 1);

		// Closes 'out.txt' descriptor in 'ofd' position.
		// There is a copy of it in position 1, so the file is still open.
		close(ofd);

		// With standard output redirected, this will be printed in out.txt
		puts(":: REDIRECTED OUTPUT ::");
		
		// exec replaces the process image, but keeps the file descriptor
		// table, hence all output will appear in 'out.txt'
		
		//execlp("./prog2b", "prog2b", NULL);
		//execlp("cat", "cat", "prog5.c", NULL);
		execlp("echo", "echo", "leic51n", NULL);
		
		puts("::: SOMETHING FAILED :::");
		puts("Are you trying to exec prog2b without "
		     "a prog2b executable in this directory?");
		
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
