

// FIXME: This doesn't handle dos line endings


#include <stdio.h>
#include <stdlib.h>


void lengths_in_file(FILE *src) {
    char *cbufp = NULL;
    int clen, cbufc;

    while ((clen = getline(&cbufp, &cbufc, src)) != -1) {
        if (*(cbufp + clen - 1) == '\n')
            cbufp[--clen] = '\0';
        printf("%6i  %s\n", clen, cbufp);
    }
    free(cbufp);
}


void lengths_in_path(char *path) {
    FILE *src;

    if ((src = fopen(path, "r")) != NULL)
        lengths_in_file(src);
    // FIXME: Give a meaningful error msg if fopen failed
}


int main(int argc, char *argv[]) {
    // FIXME: Handle '-' meaning stdin
    if (argc == 1)
        lengths_in_file(stdin);
    else
        while (--argc > 0)
            lengths_in_path(*++argv);
}
