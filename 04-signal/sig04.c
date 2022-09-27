#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

volatile bool done = false;

bool term = false;
int  tcnt = 5;

void sigIntHandler(int signum) {
	puts(" CTRL-C ignored");
}

void sigTermHandler(int signum) {
	if (!term) {
		term = true;
		puts("Terminating...");
		alarm(1);
	}
}

void sigAlarmHandler(int signum) {
	if (tcnt > 0) {
		printf(":: %d ::\n", tcnt);
		tcnt--;
		alarm(1);
	} else {
		done = true;
	}
}

int main() {

	struct sigaction actionTerm;
	memset(&actionTerm, 0, sizeof(struct sigaction));
	actionTerm.sa_handler = sigTermHandler;
	sigaction(SIGTERM, &actionTerm, NULL);

	struct sigaction actionAlarm;
	memset(&actionAlarm, 0, sizeof(struct sigaction));
	actionAlarm.sa_handler = sigAlarmHandler;
	sigaction(SIGALRM, &actionAlarm, NULL);

	struct sigaction actionInt;
	memset(&actionInt, 0, sizeof(struct sigaction));
	actionInt.sa_handler = sigIntHandler;
	sigaction(SIGINT, &actionInt, NULL);

	puts("");
	puts("Hit CTRL-C to send SIGINT which is ignored");
	puts("  or");
	printf("Run \"kill %d\" in another terminal to send SIGTERM for controlled termination\n", getpid());
	puts("");

	while (!done) {
		pause();
	}

	return 0;
}
