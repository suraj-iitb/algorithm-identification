#include <stdio.h>
int selectionSort(int*,int);
int main(){
  int A[100],i,j,N,s;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  s=selectionSort(A,N);

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1)break;
    printf(" ");
  }
  printf("\n");
  
  printf("%d\n",s);
  return 0;
}

int selectionSort(int A[],int N){
  int i,j,tmp,minj,count=0;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj=j;
    }
    if(minj!=i)count++;
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
    
  }
  return count;
}

