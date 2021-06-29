#include <stdio.h>
#define N 100

int main(){
  int i,j,k,length,count=0;
  int A[N];
  
  scanf("%d",&length);
  for(i=0;i<length;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<length;i++){
    for(j=0;j<length;j++){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	count++;
      }
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
