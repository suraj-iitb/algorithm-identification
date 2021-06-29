#include<stdio.h>
  
void print(int* A, int N){
  int i;
  for(i = 0; i < N; i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
  
int bubble_sort(int* A, int N){
  int i,j,minj,cnt = 0;
  for(i = 0; i < N; i++)
  {
      minj = i;
      for(j = i;j < N;j++)
      {
          if(A[j] < A[minj]) minj = j;
      }
      int tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      if(i!=minj) cnt++;
  }
  print(A,N);
  return cnt;
}
  
int main(){
  int i,N,data[100];
  scanf("%d",&N);
  for(i = 0; i < N; i++) scanf("%d",&data[i]);
  printf("%d\n",bubble_sort(data,N));
  return 0;
}
