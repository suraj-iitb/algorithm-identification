#include <stdio.h>

int main(){
  int i,j,N,cnt=1,A[100],num,v,count;
  scanf("%d",&N);
  while(cnt<N+1){
    scanf("%d",&num);
    if(num < 0 || num >1000)return 0;;
    A[cnt] = num;
    cnt++;
  }
  for(i=1;i<N+1;i++){
    count = 1;
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    while(count < N){
      printf("%d ",A[count]);
      count++;
    }
    printf("%d",A[count]);
    printf("\n");
  }
  return 0;
}

