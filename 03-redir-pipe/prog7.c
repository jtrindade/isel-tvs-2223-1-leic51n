#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Parent process creates a pipe, then forks a child.
// Both processes have access to the pipe, as the child's file
// descriptor table is a replica of the parent's one.
// 
// The pipe will be used to send messages from the child to the
// parent, so parent closes the writing end of the pipe and the
// child closes the reading end.
//
// (For bidirectional communication, two pipes would be needed.)
//
int main() {
	puts("prog7 running");

	int pipefd[2];
	pipe(pipefd);
	
	/*
	write(pipefd[1], "hello", 5);
	
	char msg[7];
	read(pipefd[0], msg, 5);
	msg[5] = '\n';
	msg[6] = '\0';
	puts(msg);
	*/
	
	pid_t pid = fork();
	if (pid) {
		close(pipefd[1]);

		printf("PARENT: waiting for message from child\n");
		
		char msg[256];
		
		for (;;) {
			int nr = read(pipefd[0], msg, 255);
			if (nr == 0) break;
			
			msg[nr] = '\0';
			
			printf("PARENT: message from child \"%s\"\n", msg);
		}

		printf("PARENT: DONE\n");
		
	} else {
		printf("CHILD\n");
		close(pipefd[0]);
		
		sleep(10);
		
		printf("CHILD: writing message to parent\n");
		
		write(pipefd[1], "hello, world!", 13);
		sleep(1);
		write(pipefd[1], "isel-leic51n", 13);
		sleep(1);
		write(pipefd[1], "goodbye, world", 15);

		printf("CHILD: DONE\n");
	}
	
	return 0;
}
