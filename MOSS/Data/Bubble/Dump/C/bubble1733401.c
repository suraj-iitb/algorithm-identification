#include <stdio.h>

int main(){
  int flag=1,i,j,N,cnt=0;

  //scanf N
  scanf("%d",&N);

  //making array
  int A[N];

  //complete array
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  //bubbling 
  i=0;
  while(flag){
    flag = 0;
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
        int swap = A[j];
        A[j] = A[j-1];
        A[j-1] = swap;
        cnt++; //count
        flag = 1; //to be continue
      }
    }
    i++;
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  } 
  printf("%d\n",A[i]);
  printf("%d\n",cnt);


  return 0;
}
