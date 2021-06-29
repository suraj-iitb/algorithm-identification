#include<stdio.h>

int N;

//出力する関数
void trace(int A[]){
  int i;
  for(i = 0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

//並べ替える関数
void insert(int A[]){
  int i,j,tmp;
  for(i=1;i<N;i++){
    j=i-1;
    tmp=A[i];
    while(tmp<A[j] && j>=0){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=tmp;
    trace(A);
  }

}
int main(){
  int A[100];
  int i;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  trace(A);
  insert(A);

return 0;
}
