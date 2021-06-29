#include <stdio.h>

#define N 100

int main(){
  int i,j,n,A[N],tmp,count=0,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
    if(A[i]!=A[min]){
      tmp=A[i];
      A[i]=A[min];
      A[min]=tmp;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
