#include<stdio.h>

int main(){
  int N,A[100],i,j,k,temp;

  //入力
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  //１行目の出力
  for(i=0; i<N; i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  //挿入ソート
  
  for(i=1; i<N; i++){
    temp = A[i];
    j = i-1;
    while(j>=0 && A[j]>temp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
    //２行目以降の出力
    for(k=0; k<N; k++){
      if(k>0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }
  return 0;
}

