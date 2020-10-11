#include<stdio.h>
#define N 100

int main(){
  int i,j;
  int count=0;
  int A[N];
  int num;
  int mask;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
 
  for(i=0;i<num-1;i++){
    for(j=num-1;i<j;j--){
      if(A[j]<A[j-1]){
	mask=A[j];
	A[j]=A[j-1];
	A[j-1]=mask;
	count++;
      }
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
