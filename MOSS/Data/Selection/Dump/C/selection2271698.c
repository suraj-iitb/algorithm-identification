#include <stdio.h>
#define N 100

void swap(int *,int *);
int main(){
  int n,A[N];
  int i,j,minj;
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);  
  }

  for(i=0;i<=n-2;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(minj != i) count++;
    swap(&A[i],&A[minj]);
  }
  
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",count);
  return 0;
}

void swap(int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
