#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	int result;
	char *path;

	pid_t pid;

	printf("Create a child\n");
	pid = fork();
	printf("Process %d with parent pid %d\n",getpid(),getppid());
	if(pid > 0) {
		sleep(1);
		printf("Child with pid %d created\n",pid);
		printf("Parent exiting!\n");
		return 0;
	}
	sleep(1);
	path = getenv("PATH");
	if(path != NULL)  {
		printf("Path is:%s\n",path);
	}	
	printf("Process pid %d, parent pid %d\n",getpid(),getppid());
	result = execvp("ls",argv);
	printf("SHOULD NOT GET HERE! Result:%d\n",result);
	return 0;
}
