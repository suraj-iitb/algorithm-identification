#include<stdio.h>
void swap(int *, int *);

int main(){
  int A[100],N,i,j,k,minj,cnt=0;

  //入力
  scanf("%d",&N);
  for(k=0; k<N; k++){
    scanf("%d",&A[k]);
  }

  //selection sort
  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(A[i] != A[minj]) cnt++;
    swap(&A[i],&A[minj]);
  }

  for(k=0; k<N; k++){
    if(k>0)printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  printf("%d\n",cnt);
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

  return;
}

