#include<stdio.h>
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
void insertion(int N,int A[]){
  for(int i = 1; i < N; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    print(N,A);
  }
}
#define LEN 100
int main(){
  int N,A[LEN];
  scanf("%d",&N);
  for(int i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  print(N,A);
  insertion(N,A);

}

