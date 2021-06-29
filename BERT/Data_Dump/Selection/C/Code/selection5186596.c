#include <stdio.h>

int selectionSort(int X[],int  N){
  int i,j,k,cn=0,sm;

  for(i=0;i<N-1;i++){
    sm = i;
    for(j=i;j<N;j++){
      if(X[j]< X[sm]){
        sm = j;
      }
    }
      k = X[i];
      X[i] = X[sm];
      X[sm] = k;
      if( i != sm) {
        cn++;
      }
    }
    return cn;
    }


int main(){
  int A[100],Num,i,mv;

  scanf("%d",&Num);

  for(i=0;i<Num;i++){
    scanf("%d",&A[i]);
  }

  mv = selectionSort(A,Num);

  for(i=0;i<Num;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",mv);

  return 0;
}


