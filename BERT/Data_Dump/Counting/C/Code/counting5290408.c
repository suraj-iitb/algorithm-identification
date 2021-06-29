#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max=-1;
    scanf("%d",&n);
    int A[n];
    for(int i =0; i<n; i++){
        scanf("%d",&A[i]);
        if (A[i]>max) {
            max=A[i];
        }
    }

    int k = max+1;
    int C[k], B[n];
    for(int i =0;i<k;i++) C[i]=0;
    for(int i=0; i<n; i++) {
        C[A[i]]++;
    }

    for(int i=1; i<k; i++) {
        C[i]+=C[i-1];
    }


    for(int j=0; j <n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for(int i=1; i<n+1; i++){
        printf("%d",B[i]);
        if(i==n) {
            printf("\n");
            break;
        }
        printf(" ");
    }


    return 0;
}

