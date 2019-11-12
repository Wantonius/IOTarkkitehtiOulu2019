#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) {

	sigset_t originalset;
	sigset_t signalset;


	sigemptyset(&signalset);
	
	sigaddset(&signalset,SIGINT);
	
	if(sigprocmask(SIG_BLOCK, &signalset, &originalset) < 0) {
		printf("Can't block SIGINT, exiting\n");
		return 1;
	}

	printf("Blocked SIGINT. Sleeping for 10 secs. Try CTRL+C\n");
	sleep(10);
	if(sigprocmask(SIG_UNBLOCK, &signalset, &originalset) < 0) {
		printf("Can't block SIGINT, exiting\n");
		return 1;
	}
	printf("SIGINT unblocked, exiting\n");
	return 0;
}
