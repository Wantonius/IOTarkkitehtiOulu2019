#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

#define LOG_LEVEL LOG_ERR
#define DAEMON_NAME "My test daemon"
#define LOG_FACILITY LOG_DAEMON

void daemonize(void) {

	pid_t pid;

	pid = fork();

	// pid > 0 looks for parent. Exit parent to create daemon!
	if(pid > 0) {
		printf("Parent in daemonize, exiting!\n");
		exit(EXIT_SUCCESS);
	}
	if(setsid() < 0) {
		printf("Error:%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	if(chdir("/") < 0) {
		printf("Cannot change directory. Exiting\n");
		exit(EXIT_FAILURE);
	}
	umask(0);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

int main(int argc, char **argv) {
	int i;
	pid_t pid ,ppid;

	pid = getpid();
	ppid = getppid();

	openlog(DAEMON_NAME, LOG_PID, LOG_FACILITY);
	syslog(LOG_LEVEL,"Going daemon pid:%d, parent pid:%d\n",pid,ppid);
	daemonize();
	pid = getpid();
	ppid = getppid();
	for(i=0;i<10;i++) {
		syslog(LOG_LEVEL,"Iteration %d, pid=%d, ppid=%d\n",i,pid,ppid);
		sleep(1);
	}
	syslog(LOG_LEVEL,"Daemon done\n");
	return 0;
}

