#include<stdio.h>
#define N 100

int main(){
  int i,j,min;
  int count=0;
  int A[N];
  int num;
  int mask;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<num-1;i++){
    min=i;
    for(j=i;j<num;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
    if(i!=min){
      mask=A[i];
      A[i]=A[min];
      A[min]=mask;
      count++;
    }
  }

  for(i=0;i<num;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}
