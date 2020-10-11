#include <stdio.h>
#define N 100
int main(){
  int i,j,k=0,n,tmp;
  int A[N];
  scanf("%d",&n);
  for(j=0;j<=n-1;j++){
    scanf("%d",&A[j]);
  }
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp=A[j-1];
	A[j-1]=A[j];
	A[j]=tmp;
	k++;
      }
    }
  }
  for(j=0;j<=n-1;j++){
    printf("%d",A[j]);
    if(j<n-1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",k);
  return 0;
}

