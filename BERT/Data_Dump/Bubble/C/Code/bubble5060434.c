#include<stdio.h>

int bubblesort(int A[],int N){
int j;
int tmp;
int flag = 1;
int i = 0;
 while(flag){
  flag = 0;
  for(j = N-1; j>=1 ; j--){
    if(A[j]<A[j-1]){
    tmp = A[j]; /*swap*/
    A[j] = A[j-1];
    A[j-1] = tmp;

    flag =1;
    i++;
    }
  }
 }
 return i;
}

int main(){
  int A[100];
  int N,i,k;


  scanf("%d",&N);

  for(i = 0;i<N;i++){

    scanf("%d",&A[i]);
  }

  k = bubblesort(A,N);

  for(i = 0;i<N;i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",k);

  return 0;
}

