#include<stdio.h>
void swap(int *, int *);

int main(){
  
  /* iは未ソートの先頭
   * jは未ソートの隣合う要素の比較
   * flagは逆の隣接要素があるかないか
   */
  int  A[100],N,i,j,k,flag,cnt=0;

  //入力
  scanf("%d",&N);
  for(k=0; k<N; k++){
    scanf("%d",&A[k]);
  }

  //bubble sort
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j=N-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	flag = 1;
	cnt++;
      }
    }
    i++;
  }

  //出力
  for(k=0; k<N; k++){
    if(k>0) printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}
  

