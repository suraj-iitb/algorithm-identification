#include <stdio.h>

int main(){
  int A[10000];
  int B[500];
  int i,j;
  int X,Y,key;
  int count = 0;

  scanf("%d",&X);

  for(i=0;i<X;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&Y);

  for(i=0;i<Y;i++){
    scanf("%d",&B[i]);
  }
  
  for(i=0;i<Y;i++){
    key = B[i];
    for(j=0;j<X;j++){
      if(A[j]==key){
	count += 1;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

