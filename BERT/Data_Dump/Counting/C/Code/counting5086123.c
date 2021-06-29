#include <stdio.h>
#define MAX 2000001
#define VMAX 10000

int main(){
    int n,i,max=0,A[MAX],B[MAX],C[MAX];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        if(A[i]>max) max=A[i];
        C[i-1]=0;
    }
    for(i=1;i<=n;i++) C[A[i]]++;
    for(i=1;i<max+1;i++) C[i]+=C[i-1];
    for(i=n;i>0;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
    for(i=1;i<n;i++) printf("%d ",B[i]);
    printf("%d\n",B[n]);
  return 0;
}
