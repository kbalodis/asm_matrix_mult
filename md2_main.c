#include <stdio.h>
#include "md2.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int  w1, w2, h1, h2;
    int *matrix1, *matrix2, *matrix3; 
    int *p;
    char tmp[256];
    char *end;
    long check;

    for(int i = 0; i < 256; i++) tmp[i] = '\n';
    if (1 != scanf("%s", tmp)) {
        exit(1);
    } else {
        errno = 0;
        check = strtol(tmp, &end, 10);
        if (tmp == end) {
            exit(1);
        }
        if (errno == 0) {
            if (check < INT_MIN ||  check > INT_MAX) {
                exit(1);
            } else {
                h1 = (int)check;
            }
        } else {
            exit(1);
        }
    }

    for(int i = 0; i < 256; i++) tmp[i] = '\n';
    if (1 != scanf("%s", tmp)) {
        exit(1);
    } else {
        errno = 0;
        check = strtol(tmp, &end, 10);
        if (tmp == end) {
            exit(1);
        }
        if (errno == 0) {
            if (check < INT_MIN ||  check > INT_MAX) {
                exit(1);
            } else {
                w1 = (int)check;
            }
        } else {
            exit(1);
        }
    }

    /* Buferu alokācija un cikls pa visiem matricas elementiem */
    matrix1 = (int*) malloc( w1 * h1 * sizeof(int));
    p = matrix1;
    for(int i = 0; i < w1*h1; i++)
    {
        for(int i = 0; i < 256; i++) tmp[i] = '\n';
        if (1 != scanf("%s", tmp)) {
            exit(1);
        } else {
            errno = 0;
            check = strtol(tmp, &end, 10);
            if (tmp == end) {
                exit(1);
            }
            if (errno == 0) {
                if (check < INT_MIN ||  check > INT_MAX) {
                    exit(1);
                } else {
                    *p = (int)check;
                    p++;
                }
            } else {
                exit(1);
            }
        }
    }

    for(int i = 0; i < 256; i++) tmp[i] = '\n';
    if (1 != scanf("%s", tmp)) {
        exit(1);
    } else {
        errno = 0;
        check = strtol(tmp, &end, 10);
        if (tmp == end) {
            exit(1);
        }
        if (errno == 0) {
            if (check < INT_MIN ||  check > INT_MAX) {
                exit(1);
            } else {
                h2 = (int)check;
            }
        } else {
            exit(1);
        }
    }

    for(int i = 0; i < 256; i++) tmp[i] = '\n';
    if (1 != scanf("%s", tmp)) {
        exit(1);
    } else {
        errno = 0;
        check = strtol(tmp, &end, 10);
        if (tmp == end) {
            exit(1);
        }
        if (errno == 0) {
            if (check < INT_MIN ||  check > INT_MAX) {
                exit(1);
            } else {
                w2 = (int)check;
            }
        } else {
            exit(1);
        }
    }
 
    /* Buferu alokācija un cikls pa visiem matricas elementiem */
    matrix2 = (int*) malloc( w2 * h2 * sizeof(int));
    p = matrix2;
    for(int i = 0; i < w2*h2; i++)
    {
        for(int i = 0; i < 256; i++) tmp[i] = '\n';
        if (1 != scanf("%s", tmp)) {
            exit(1);
        } else {
            errno = 0;
            check = strtol(tmp, &end, 10);
            if (tmp == end) {
                exit(1);
            }
            if (errno == 0) {
                if (check < INT_MIN ||  check > INT_MAX) {
                    exit(1);
                } else {
                    *p = (int)check;
                    p++;
                }
            } else {
                exit(1);
            }
        }
    }

    matrix3 = (int*) malloc( h1 * w2 * sizeof(int));
    for(int i = 0; i < h1*w2; i++)
        matrix3[i] = 0;

    int ret = matmul(h1, w1, matrix1, h2, w2, matrix2, matrix3);

    if (!ret) {
        printf("%d %d ", h1, w2);
        for(int i = 0; i < h1*w2; i++)
            if (i == h1 * w2 - 1)
                printf("%d", matrix3[i]);
            else
                printf("%d ", matrix3[i]);
    } else {
        exit(1);
    }

    return 0;
}