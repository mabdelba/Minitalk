#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void handler(int sig, siginfo_t *info, void *ucontext)
{

	printf("UID : %d\n", info->si_pid);
	printf("I won't die\n");
	exit(1);
}

int main()
{
	
	struct sigaction new, old;

	memset(&new, 0, sizeof(struct sigaction));
	new.sa_sigaction = handler;
	new.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &new, &old);

	int *ptr;

	*ptr = 1;
	int i = 0;
	while (i < 10)
	{
		printf("I'm running...!\n");
		sleep(1);
		i++;
	}
	sigaction(SIGINT, &old, NULL);
	i = 0;
	while (i < 10)
	{
		printf("I'm running again..,\n");
		sleep(1);
		i++;
	}


}
