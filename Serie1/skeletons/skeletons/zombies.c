/* gcc -Wall -std=gnu99 zombies.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_zombie() {
	
	pid_t pids[10];
	int i;
	
	for(i = 9; i >= 0; i--){
	
		pids[i] = fork();
		if (pids[i] == 0) {
			sleep(i+1);
			_exit(0);
		}

	}
	
	for (i = 9; i >= 0; --i){
		waitpid(pids[i], NULL, 0);
	}
	
	return;
}

int main(void)
{
	int wait = 15;
	/* TODO: implement */

	create_zombie();
	return 0;
}
