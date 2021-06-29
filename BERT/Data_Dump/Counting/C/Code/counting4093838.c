#include <stdio.h>
#define RANGE 10010
 
int C[RANGE] = {0};
 
int main()
{
    int i, j;
    int N;
    int a;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &a);
        C[a]++;
    }
     
    int last = 0;
    for (i=0; i<RANGE; i++) {
        if (C[i] != 0) {
            last = i;
        }
    }
     
    for (i=0; i<last; i++) {
        for (j=0; j<C[i]; j++) {
            printf("%d ", i);            
        }
    }
    for (i=0; i<C[last]-1; i++) {
        printf("%d ", last);
    }
    printf("%d\n", last);
     
    return 0;
}

