#include <stdio.h>
#include <stdlib.h>

int cts(unsigned int*,unsigned int*,int,int);

int main(int argc, const char * argv[]) {
    int n;
    int i;
    unsigned int A[2000000];
    unsigned int B[2000000];
    scanf("%d",&n);
    scanf("%d",&A[1]);
    int k=A[1];
    for( i=2;i<=n;i++){
        scanf("%d",&A[i]);
        if(A[i]>=k) k=A[i]; 
    }
    cts(A,B,k,n);
    
    for(i=1;i<=n;i++){
        printf("%d",B[i]);
        if(i!=n) printf(" ");
        else printf("\n");
    }
    
    return 0;
}

int cts(unsigned int A[],unsigned int B[], int k, int n){
    int C[10000];
    int i;
    for(i=0;i<=k;i++){
        C[i]=0;
    }
    for(i=1;i<=n;i++){
        C[A[i]]=C[A[i]]+1;        
    }
    for(i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=n;i>=1;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]=C[A[i]]-1;
    }
    return 100;
}
