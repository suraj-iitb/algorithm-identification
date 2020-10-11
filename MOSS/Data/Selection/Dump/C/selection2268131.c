#include<stdio.h>
#define N 100

int main(){
  int i,j,n,tmp,min,count=0,A[N];
  
  scanf("%d",&n);
  for(i=0 ; i<n; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0 ; i<n-1 ; i++){
    min=i;
    for(j=i ; j<n ; j++){
      if(A[j]<A[min])
	min=j;
    }
    if(min != i)count++;
    
    tmp=A[i];
    A[i]=A[min];
    A[min]=tmp;
    
  }
  for(i=0 ; i<n ; i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}
