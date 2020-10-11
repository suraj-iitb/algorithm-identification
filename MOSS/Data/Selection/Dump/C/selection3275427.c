#include<stdio.h>
#define N 100
int main(){
  int n,i,j=0,A[N],b,minj,k,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj])minj = j;
    }
    k = A[i];
    A[i] = A[minj];
    A[minj] = k;
    if(i != minj) count++;
    
  }
    for(b=0;b<n-1;b++) printf("%d ",A[b]);
    printf("%d",A[n-1]);
    printf("\n");
    printf("%d",count);
    printf("\n");
    
  return 0; 
}

