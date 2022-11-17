#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "svc.h"

// int mkfifo(const char *pathname, mode_t mode);

// #define offsetof(TYPE, MEMBER) ((size_t)&(((TYPE*)0)->MEMBER))

int main(int argc, char * argv[]) {
	puts(":: STARTING ::");

	char * fifoname = argc > 1 ? argv[1] : "isel-fifo";
	
	char * fifo_path = malloc(strlen(FIFO_DIR) + strlen(fifoname) + 1);
	sprintf(fifo_path, "%s%s", FIFO_DIR, fifoname);
	
	int mkres = mkfifo(fifo_path, 0666);
	if (mkres == -1) {
		perror("Failed to create FIFO");
		exit(1);
	}
	
	int fd = open(fifo_path, O_RDONLY);
	if (fd == -1) {
		perror("Failed to open FIFO");
		exit(2);
	}
	
	for (;;) {
		msg_t msg;
		int rres;
		
		rres = read(fd, &msg, offsetof(msg_t, txt));
		if (rres == -1) {
			perror("Failed to read from FIFO");
			exit(3);
		}
		if (rres == 0) {  // Escritor desapareceu.
			break;
		}
		
		char * msg_txt = malloc(msg.len + 1);
		if (msg.len > 0) {
			rres = read(fd, msg_txt, msg.len);
			if (rres == -1) {
				perror("Failed to read from FIFO");
				exit(3);
			}
			if (rres == 0) {
				break;
			}
		}
		msg_txt[msg.len] = 0;

		printf("MSG from %d : \"%s\"\n", msg.pid, msg_txt);
		free(msg_txt);
	}
	
	puts(":: TERMINATING ::");
	close(fd);
	unlink(fifo_path);
	free(fifo_path);
	
	return 0;
}
