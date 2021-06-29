#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){
  int N;
  int i,j;
  int *A;
  int key;
  scanf("%d",&N);//読み込み完了
  
  A=malloc(N*sizeof(int));
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
  for(i=0;i<N;i++){
    key=A[i];
    for(j=i-1;j>=0;j--){
      if( key >= A[j]) break;
      A[j+1]=A[j];
    }
    A[j+1]=key;
    for(j=0;j<N-1;j++) printf("%d ",A[j]);
    printf("%d\n",A[N-1]);
  }
  return 0;
}
