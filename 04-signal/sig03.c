#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main() {

	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGALRM, SIG_IGN);

	alarm(20);
	
	puts("");
	puts("Hit CTRL-C to send SIGINT  [IGNORED]");
	puts("  or");
	printf("Run \"kill %d\" in another terminal to send SIGTERM  [IGNORED]\n", getpid());
	puts("  or");
	puts("Wait 20 seconds for SIGALRM  [IGNORED]");
	puts("");

	printf("Run \"kill -USR1 %d\" in another terminal to send SIGUSR1\n", getpid());
	puts("");
	
	pause();

	return 0;
}
