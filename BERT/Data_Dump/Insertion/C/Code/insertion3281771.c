#include <stdio.h>
#define N 1000

int main()
{
    int A[N];
    int num,v;
    int i, j, k;

    scanf("%d",&num);
    for(i = 0; i < num; i++){
        scanf("%d",&A[i]);
    }

    for (i=0; i < num; i++) {
        v = A[i];
        j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = v;

        for(k = 0; k < num; k++){
            if(k)printf(" ");
            printf("%d",A[k]);
            }   
        printf("\n");
        }
    return 0;
}

