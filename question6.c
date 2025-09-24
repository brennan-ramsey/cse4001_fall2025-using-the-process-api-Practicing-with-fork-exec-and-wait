#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("PID (pid:%d)\n", (int) getpid());
    int id = fork();

    if (id < 0) { // id is negative; failed
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (id == 0) { // is child
        printf("I am child. Hello!\n");
    } else { // is parent
	waitpid(0, NULL, 0);
        printf("I am parent. Goodbye!\n");
    }

    return 0;
}
