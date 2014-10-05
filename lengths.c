

// FIXME: This doesn't handle dos line endings


#include <stdio.h>

// FIXME: Really want to handle lines of any length
//  (see if linebuffer in gnulib would help)
#define LINELEN 2048

#define NOMORELINES -1


int read_a_line(FILE *src, char cbuf[]) {
    int clen = 0;
    char c;
    int looped = 0;

    // FIXME: Doesn't handle buffer overflows!
    while ((c = getc(src)) != EOF) {
        looped = 1;
        if (c == '\n') {
            break;
        } else {
            cbuf[clen++] = c;
        }
    }
    cbuf[clen] = '\0';
    if (looped)
        return clen;
    else
        return NOMORELINES;
}


void lengths(FILE *src) {
    char cbuf[LINELEN];
    int clen;

    while ((clen = read_a_line(src, cbuf)) != NOMORELINES) {
        printf("%6i  %s\n", clen, cbuf);
    }
}


int main(int argc, char *argv[]) {
    // FIXME: read files listed in cmd line args
    lengths(stdin);
}


