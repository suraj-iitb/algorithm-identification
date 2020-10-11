#include<stdio.h>

int selectionSort(int A[],int N){
  int i,j,minj,n,cnt=0;
  
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    n=A[i];
    A[i]=A[minj];
    A[minj]=n;
    if(i!= minj) cnt++;
  }
  return cnt;
  
}


int main(){
  int n,i,cnt=0;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  cnt=selectionSort(A,n);

  for(i=0;i<n-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d",A[n-1]);

  printf("\n");
  printf("%d\n",cnt);
}

