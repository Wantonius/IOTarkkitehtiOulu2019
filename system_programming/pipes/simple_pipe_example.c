#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int child_action(int pipefd) {
	int m;
	char buffer[256];

	memset(buffer,0,256);
	printf("Send message to the parent\n");
	fgets(buffer,255,stdin);
	m = write(pipefd,buffer,strlen(buffer));
	printf("Wrote %d bytes to the parent\n",m);
	return 0;	
}

int main(int argc, char **argv) {
	int pipefd[2], n;
	int pid;
	char buffer[256];

	n = pipe(pipefd);
	if(n < 0) {
		printf("Error creating pipes. Error:%s\n",strerror(errno));
		return 1;
	}
	pid = fork();
	if(pid == 0) {
		child_action(pipefd[1]);
		return 0;
	}
	printf("Waiting for a message from child\n");
	memset(buffer, 0, 256);
	n = read(pipefd[0], buffer, 256);
	if(n>0) {
		printf("Message (size:%d) from child:%s\n",n,buffer);
	}
	return 0;
}	
