#include<stdio.h>

static inline void disp(short n, short *a)
{
    short i;

    printf("%hd", a[0]);
    for(i=1; i<n; ++i)printf(" %hd", a[i]);
    printf("\n");
}

int main(void)
{
    short n, i, j;
    short a[100], v;

    scanf("%hd", &n);
    for(i=0; i<n; ++i)scanf("%hd", a+i);

    disp(n,a);
    for(i=1; i<n; ++i){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
        disp(n,a);
    }

    return 0;
}
