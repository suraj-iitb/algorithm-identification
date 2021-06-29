#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE         (1024)

char buf[BUFSIZE];

long
readnum()
{
    long        ret;
    char        *bp;

    bp = fgets(buf, BUFSIZE, stdin);
    if (bp == NULL) goto err;
    ret = atol(buf);
    return ret;

  err:
    perror("error fgets");
    exit(EXIT_FAILURE);
}

void
print_arr(int *arr, int sz)
{
    int idx;

    printf("%d", arr[0]);    
    for (idx = 1; idx < sz; ++idx) {
        printf(" %d", arr[idx]);
    }
    puts("");
}


#define MAX(a, b)       ((a) < (b) ? (b) : (a))
#define MIN(a, b)       ((a) > (b) ? (b) : (a))

int
main()
{
    long        num;
    int         na[100];
    long        tn;
    int         idx;
    char        *rp;
    char        *nrp;
    int         ic;
    int         rv;
    
    tn = readnum();

    rp = fgets(buf, BUFSIZE, stdin);
    for (idx = 0; idx < tn; ++idx) {
        num = strtol(rp, &nrp, 10);
        na[idx] = num;
        if (rp == nrp) goto err;
        rp = nrp;
    }
    print_arr(na, tn);

    for (ic = 1; ic < tn; ++ic) {
        rv = na[ic];
        for (idx = ic; 0 < idx; --idx) {
            if (na[idx - 1] < rv) break;
            na[idx] = na[idx - 1];
        }
        na[idx] = rv;
        print_arr(na, tn);
    }
    exit(EXIT_SUCCESS);

  err:
    exit(EXIT_FAILURE);
}

