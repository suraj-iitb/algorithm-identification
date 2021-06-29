#include<stdio.h>
int main(){
  int N,i,j,minj,temp,cout=0;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])minj=j;
    }
    if(minj!=i){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      cout++;
    }
  }
  printf("%d",A[0]);
  for(i=1;i<N;i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",cout);
  return 0;
}

