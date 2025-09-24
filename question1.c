#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("PID (pid:%d)\n", (int) getpid());
    int x = 10;
    int id = fork();

    if (id < 0) { // id is negative; failed
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (id == 0) { // is child
	x = x+10; // x = 20
        printf("Child (pid:%d) (x:%d)\n", (int) getpid(), x);
    } else { // is parent
	x = x-5; // x = 5
        printf("Parent of %d (pid:%d) (x:%d)\n", id, (int) getpid(), x);
    }

    return 0;
}
