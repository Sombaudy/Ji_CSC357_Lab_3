#include <stdio.h>
#include <stdlib.h>


int main() {
    char *path = "/usr/lib/locale/locale-archive";
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("file");
        exit(-1);
    }


    char buffer[8192];
    int bytes = fread(buffer, 1, sizeof(buffer), file);
    //printf("%d bytes read.\n", bytes);

    //printf("%s", buffer);


    fclose(file);
    return 0;
}