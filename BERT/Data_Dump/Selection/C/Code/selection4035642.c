#include <stdio.h>

int selectionSort(int A[],int N)
{
  int i,j,minj,a,b,count=0; 

  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]>A[minj]) count++;
    a=A[i];
    b=A[minj];
    A[i]=b;
    A[minj]=a;
  }
  return count;
}


int main(){
  int i,j,N,count;
   scanf("%d",&N);
 
  int A[N];
  for(i=0; i<N ;i++){
    scanf("%d",&A[i]);
  }

  count=selectionSort(A,N);

  for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",count);

  
  return 0;
}

