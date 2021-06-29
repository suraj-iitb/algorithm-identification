#include<stdio.h>
int main(){
    int i,j,n,s,count=0;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    for(i=0;i<n;i++){
     for(j=n-1;j>=1;j--){
      if(A[j] < A[j-1]){
          count++;
          s = A[j-1];
          A[j-1] = A[j];
          A[j] = s;
      }
     }
    }
    for(i=0;i<n-1;i++) printf("%d ",A[i]);
    printf("%d\n%d\n",A[n-1],count);
    return 0;
}


