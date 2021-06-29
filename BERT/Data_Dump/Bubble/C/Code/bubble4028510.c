#include <stdio.h>
#define MAX 100

int BubbleSort(int A[],int N){

  int flag =1;
  int i;
  int cnt=0;
  
  while(flag){
    flag =0;
    for(i=N-1; i>0; i--){
      if(A[i] < A[i-1]){
        int tmp;
        tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        cnt++;
        flag=1;
      }
    }
  }
  return cnt;
}


int main(){
  int N;
  int A[MAX];
  int ans,i;

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&A[i]);

  ans = BubbleSort(A,N);
  for(i=0; i<N; i++){
    if(i !=0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",ans);

  return 0;
}

