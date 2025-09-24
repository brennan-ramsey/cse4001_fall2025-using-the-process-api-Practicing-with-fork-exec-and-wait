#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void) {
    printf("PID (pid:%d)\n", (int) getpid());
    int file = open("words.txt", O_RDWR);
    char *start = "Hello world!\n";
    write(file, start, strlen(start));
    int id = fork();

    if (id < 0) { // id is negative; failed
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (id == 0) { // is child
	char *text = "Child!\n";
	write(file, text, strlen(text));
        printf("Child (pid:%d)\n", (int) getpid());
    } else { // is parent
	char *text = "Parent!\n";
	write(file, text, strlen(text));
        printf("Parent of %d (pid:%d)\n", id, (int) getpid());
    }

    return 0;
}

