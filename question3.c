#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("PID (pid:%d)\n", (int) getpid());
    int id = fork();

    if (id < 0) { // id is negative; failed
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (id == 0) { // is child
        printf("hello\n");
    } else { // is parent
	sleep(1);
        printf("goodbye\n");
    }

    return 0;
}
