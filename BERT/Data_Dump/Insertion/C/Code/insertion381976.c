#include<stdio.h>

int main(void){
  int i,j;
  int key;
  int A[100];
  int N;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

    for(i=0;i<N;i++){
      if(i>0)printf(" ");
      printf("%d",A[i]);
    }

    printf("\n");

  for(j=1;j<N;j++){
    key=A[j];
    i=j-1;

    while(1){
      if(i>=0 && A[i]>key){
	A[i+1]=A[i];
	i=i-1;
      }
      else break;
    }

    A[i+1]=key;

    for(key=0;key<N;key++){
      if(key>0)printf(" ");
      printf("%d",A[key]);
    }

    printf("\n");

  }
  return 0;

}
