/** selection sort by ascending order **/

#include <stdio.h>

int main(){
  int i,j,N,cnt=0,swap,minj;

  //scanf N
  scanf("%d",&N);

  //making array
  int A[N];

  //complete array
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  //selecting
  for(i=0;i<N-1;i++){
    minj = i; //first
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){ //update minj
        minj = j;
      }
    }
    //changing
    if(minj != i) {
      swap = A[i];
      A[i] = A[minj];
      A[minj] = swap;
      cnt++; //count
    }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  } 
  printf("%d\n",A[i]);
  printf("%d\n",cnt);


  return 0;
}
