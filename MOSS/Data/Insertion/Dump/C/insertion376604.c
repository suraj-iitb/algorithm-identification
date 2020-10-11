#include<stdio.h>

int main(){
  int N;
  int A[101];
  int i,j,k,key;

  /*load the N*/
  scanf("%d",&N);
  /*load number*/
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
  }

  /*algorithm*/
  for(j=1;j<=N;j++){
    key=A[j];
    i=j-1;
    while(i>=0 && A[i]>key){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;

    /*print*/
    for(k=1;k<=N;k++){
      printf("%d",A[k]);
      if(k!=N)printf(" ");
    }
    printf("\n");
  }

  return 0;
}
