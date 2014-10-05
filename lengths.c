

// FIXME: This doesn't handle dos line endings


#include <stdio.h>
#include <stdlib.h>


void lengths(FILE *src) {
    char *cbufp = NULL;
    int clen, cbufc;

    while ((clen = getline(&cbufp, &cbufc, src)) != -1) {
        if (*(cbufp + clen - 1) == '\n')
            cbufp[--clen] = '\0';
        printf("%6i  %s\n", clen, cbufp);
    }
    free(cbufp);
}


int main(int argc, char *argv[]) {
    // FIXME: read files listed in cmd line args
    lengths(stdin);
}
