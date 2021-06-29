#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int
readnar(char *buf, long *nar, int sz)
{
    int         idx;
    char        *rp;
    char        *nrp;
    long        num;

    rp = buf;
    for (idx = 0; idx < sz; ++idx) {
        num = strtol(rp, &nrp, 10);
        *nar = num;
        ++nar;
        if (rp == nrp) break;
        rp = nrp;
    }
    return idx;
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

bool
binsearch(long key, long *nar, int nsz)
{
    bool        ret;
    int         aa = 0;
    int         bb = nsz - 1;
    int         mm;

    ret = false;
    while (aa <= bb) {
        mm = (aa + bb) / 2;
        if (nar[mm] == key) return true;
        if (nar[mm] < key) {
            aa = mm + 1;
        } else {
            bb = mm - 1;
        }
    }
    return ret;
}

#define SAMAX    (10 * 10000)

int
main()
{
    long        num;
    long        snar[SAMAX];
    long        sn;
    long        tn;
    int         nr;
    int         idx;
    int         cnt;
    
    sn = readnum();
    for (idx = 0; idx < sn; idx++) {
        nr = scanf(" %ld", &num);
        if (nr <= 0) goto err;
        //printf("[%d] = %ld ", idx, num);
        snar[idx] = num;
    }
    fgets(buf, BUFSIZE, stdin); // flush
        
    tn = readnum();
    //printf("tn = %ld\n", tn);
    cnt = 0;
    for (idx = 0; idx < tn; idx++) {
        nr = scanf(" %ld", &num);
        if (nr <= 0) goto err;
        //printf("[%d] = %ld ", idx, num);
        if (binsearch(num, snar, sn)) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);

    exit(EXIT_SUCCESS);

  err:
    exit(EXIT_FAILURE);
}

