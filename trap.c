#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT){
    printf("received SIGINT  yet the process lives on hahaha\n");
  }
}

int main(void)
{

// Register the signal handler  
//signal(SIGSEGV, segfault_handler); tells the OS:
//If a SIGSEGV occurs, call segfault_handler instead of the default behavior (which is to terminate the program).
// Match up different / more signal names here 

  if (signal(SIGINT, sig_handler) == SIG_ERR){
  	printf("\ncan't catch SIGINT\n");
  }
  
  // A long long wait so that we can easily issue a signal to this process
  while(1){ 
    printf("tick tock..");
	  sleep(1000);
  }
  return 0;
}
