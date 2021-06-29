#include <stdio.h>
#include<stdlib.h>
#define N 1000

int main()
{
    int a,b,i,j;
    int A[N];
    int v;

    scanf("%d",&a);
    if(a > 100)exit(1);
    for(i = 0 ; i < a ; i++){
    scanf("%d",&A[i]);
    printf("%d",A[i]);
    if(i < a - 1)printf(" ");
    }
    printf("\n");
    for(i = 1 ; i < a ; i++){
        v = A[i];
        j = i - 1;
        while(v < A[j] && j >= 0){
            A[j + 1] = A[j];
            j--;
            A[j + 1] = v;
        }
        for(b = 0; b < a ; b++){
            printf("%d",A[b]);
            if(b < a - 1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}

