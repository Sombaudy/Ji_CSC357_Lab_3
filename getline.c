#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("not enough arg\n");
        exit(-1);
    }

    char *filename = argv[1];
    //printf("%s\n", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        exit(-1);
    }

    int count = 1;
    char c;

    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') 
            count = count + 1;
    }
    printf("the file %s has %d lines\n", argv[1], count);

    rewind(file);


    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;


    if (count == 1) {
        fseek (file, 0, SEEK_END);
        int size = ftell(file);

        if (0 == size) {
            printf("file is empty\n");
        } else {
            getline(&line, &len, file);
            printf("%s", line);
        }
        free(line);
    } else {
        int skip = count - 2;
        while (skip > 0) {
            c = getc(file);
            if (c == '\n')
                skip = skip - 1;
        }
        
        while ((read = getline(&line, &len, file)) != -1) {
            //printf("Retrieved line of length %zu :\n", read);
            printf("%s", line);
        }
        free(line);
        printf("\n");
    }

    fclose(file);
    return 0;
}

