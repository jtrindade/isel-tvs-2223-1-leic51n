#include <unistd.h>
#include <stdio.h>

int main() {

	puts("");
	puts("Hit CTRL-C to send SIGINT");
	puts("  or");
	printf("Run \"kill %d\" in another terminal to send SIGTERM\n", getpid());
	puts("");
	
	pause();

	return 0;
}
