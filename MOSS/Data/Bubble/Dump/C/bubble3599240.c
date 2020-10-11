#include<stdio.h>
#define LEN 100
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
int bubble(int N,int A[]){
  int flag = 1;
  int cnt = 0;
  while(flag==1){
    flag = 0;
    for(int j = N - 1; j > 0; j--){
      if(A[j] < A[j - 1]){
        cnt++;
        int temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        flag = 1;
      }
    }
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

  int cnt = bubble(N,A);
  print(N,A);
  printf("%d\n",cnt);
}

