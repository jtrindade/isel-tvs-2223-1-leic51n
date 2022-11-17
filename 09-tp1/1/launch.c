#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

	int pipefd[2];
	pipe(pipefd);
	
	int pid1 = fork();
	if (pid1 == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		
		execlp("./ex1", "ex1", "18", NULL);
		exit(1);
	}
	
	int pid2 = fork();
	if (pid2 == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		
		int outfd = open("output1.txt", O_CREAT|O_WRONLY, 0644);
		dup2(outfd, 1);
		close(outfd);
		
		execlp("grep", "grep", "1", NULL);
		exit(1);
	}
	
	close(pipefd[0]);
	close(pipefd[1]);
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	
	return 0;
}
