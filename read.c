#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ARR_SIZE 1

int main() {
    char *path = "/usr/lib/locale/locale-archive";
    int fd = open(path, O_RDONLY | O_EXCL);
    if (fd < 0) {
        perror("fd");
        exit(1);
    }

    //printf("fd = %d\n", fd);


    char buffer[8192];
    int b = read(fd, buffer, sizeof(buffer));
    //printf("%d bytes read.\n", b);

    //printf("%s", buffer);


    if (close(fd) < 0) {
        perror("fd");
        exit(1);
    }
    //printf("closed the fd.\n");
    return 0;
}