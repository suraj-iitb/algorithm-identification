#include<stdio.h>
#define LEN 100
void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void print(int N,int A[]){
  for(int i = 0; i < N; i++){
    if(i < (N - 1) ){
      printf("%d ",A[i]);
    }else{
      printf("%d",A[i]);
    }
  }
  putchar('\n');
}

int selection(int N,int A[]){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    swap(&A[i],&A[minj]);
    if(i != minj) cnt++;
  }
  return cnt;
}


int main(){
  int N;
  scanf("%d",&N);
  int A[LEN];
  for(int i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  int cnt = selection(N,A);
  print(N,A);
  printf("%d\n",cnt);
}

