#include "stdlib.h"
#include "unistd.h"

const char * FIFO_DIR = "/tmp/";

typedef struct msg {
	pid_t  pid;
	size_t len;
	char   txt[1];
} msg_t;
