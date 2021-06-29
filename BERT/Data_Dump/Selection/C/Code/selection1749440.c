#include <stdio.h>
#define N 100

int main(){
  int i,j,k,length,count=0,mini;
  int A[N];
  
  scanf("%d",&length);
  for(i=0;i<length;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<length;i++){
    mini=i;
    for(j=i;j<length;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    if(i<mini){
      k=A[i];
      A[i]=A[mini];
      A[mini]=k;
      count++; 
    }
  }
  
  for(i=0;i<length;i++){
    printf("%d",A[i]);
    if(i!=length-1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
