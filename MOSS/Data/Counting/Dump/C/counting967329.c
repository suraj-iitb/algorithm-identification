#include <stdio.h>

int A[2000000],B[2000001];

int main(int argc, char *argv[]){
    int n,k=0;
    int i,j;
    
    int C[10000]={0};
    
    scanf("%d",&n);
    
    
    
    if(1>n || n>2000000)return 0;
    
    
  //  int B[n];
    
    /* incert */
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        if(A[i]>=k)k=A[i];
    }
    
    for(i=0;i<k;i++){
        C[i]=0;
    }
    
    for(j=1;j<=n;j++){
        C[A[j]]++;
    }
    
    for(i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    
    for(j=n;j>=1;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    
    for(i=1;i<n;i++){
        printf("%d ",B[i]);
    }
    printf("%d\n",B[n]);
    /**/
    return 0;
}// End main
