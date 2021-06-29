#include <stdio.h>
#define MAX 20000500
#define K 10000

void CountingSort(int);

int A[MAX],B[MAX],C[MAX],n;

int main(){
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    CountingSort(K);

    for(i=1;i<=n;i++){
        printf("%d",B[i]);
        if(i==n)printf("\n");
        else printf(" ");
    }
    return 0;
}

void CountingSort(int k){
    int i,j;
    for(i=0;i<k;i++){/*reset*/
        C[i] = 0;
    }
    
    for(j=0;j<n;j++){/*count*/
        C[A[j]] = C[A[j]] + 1;
    }

    for(i=1;i<k;i++){/*sum*/
        C[i] = C[i] + C[i-1];
    }

    for(j=n-1;j>=0;j--){/*sort*/
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
