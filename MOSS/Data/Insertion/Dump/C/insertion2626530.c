#include<stdio.h>
void insertionsort(int num[], int array_size){
  int i,j,k;
  for(i=1;i<array_size;i++){
    int v = num[i];
    j=i-1;
    while((j>=0)&&(num[j]>v)){
      num[j+1] = num[j];
      j--;
    }
    num[j+1]=v;
    for(k=0;k<array_size;k++){
      if(k>=1)printf(" ");
      printf("%d",num[k]);
    }
    printf("\n");
  }
}

int main(){
  int N,i;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for (i = 0; i < N;i++){
    if(i>=1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  insertionsort(A,N);
  return 0;
}
