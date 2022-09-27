#include <unistd.h>
#include <stdio.h>

int main() {

	alarm(20);
	
	puts("");
	puts("Hit CTRL-C to send SIGINT");
	puts("  or");
	printf("Run \"kill %d\" in another terminal to send SIGTERM\n", getpid());
	puts("  or");
	puts("Wait 20 seconds for SIGALRM");
	puts("");
	
	pause();

	return 0;
}
