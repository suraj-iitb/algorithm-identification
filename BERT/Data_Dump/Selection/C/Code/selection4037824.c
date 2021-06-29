#include <stdio.h>
#define N 100
int main(){
  int i,j,k=0,n,tmp,min,flag;
  int A[N];
  scanf("%d",&n);
  for(j=0;j<=n-1;j++){
    scanf("%d",&A[j]);
  }
  for(i=0;i<=n-1;i++){
    flag=0;
    min=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[min]){
	min=j;
	flag=1;
      }
    }
    if(flag==1){
      tmp=A[i];
      A[i]=A[min];
      A[min]=tmp;
      k++;
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

