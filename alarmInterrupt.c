#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigalrm(int sig) {
    printf("\n[!] Timeout: No input received within 5 seconds.\n");
    exit(1);
}

int main() {
    char name[100];

    // Set up SIGALRM handler
    signal(SIGALRM, handle_sigalrm);

    printf("Enter your name: ");
    fflush(stdout);

    alarm(5);  // Set alarm for 5 seconds

    if (fgets(name, sizeof(name), stdin)) {
        alarm(0);  // Cancel alarm
        printf("Hello, %s", name);
    }

    return 0;
}
