#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "svc.h"

int main(int argc, char * argv[]) {

	if (argc < 3) {
		fprintf(stderr, "use: %s fifoname msg1 msg2 msg3 ...\n", argv[0]);
		exit(1);
	}

	char * fifo_path = malloc(strlen(FIFO_DIR) + strlen(argv[1]) + 1);
	sprintf(fifo_path, "%s%s", FIFO_DIR, argv[1]);

	int fd = open(fifo_path, O_WRONLY);
	if (fd == -1) {
		perror("Failed to open FIFO");
		exit(2);
	}

	for (int i = 2; i < argc; ++i) {
		size_t mlen = strlen(argv[i]);
		size_t tlen = offsetof(msg_t, txt) + mlen;
		msg_t * pmsg = malloc(tlen);
		pmsg->pid = getpid();
		pmsg->len = mlen;
		strcpy(pmsg->txt, argv[i]);
		
		int wres = write(fd, pmsg, tlen);
		if (wres == -1) {
			perror("Failed to write to FIFO");
			exit(4);
		}
		free(pmsg);

		sleep(3);
	}
	
	close(fd);
	free(fifo_path);
	
	return 0;
}
