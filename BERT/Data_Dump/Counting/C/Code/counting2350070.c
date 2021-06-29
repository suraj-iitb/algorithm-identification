#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,j;
    int *A,*B;
    int C[10001];
    
    scanf("%d",&n);
    
    A=malloc(sizeof(int)*n);
    B=malloc(sizeof(int)*n);
    
    for(i=0;i<10001;i++){
        C[i]=0;
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&A[i+1]);
        C[A[i+1]]++;
    }
    for(i=1;i<10001;i++){
        C[i]+=C[i-1];
    }
    for ( j = 1; j <= n; j++ ){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for ( i = 1; i <= n; i++ ){
        if(i>1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}
