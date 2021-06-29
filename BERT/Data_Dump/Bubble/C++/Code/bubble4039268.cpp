#include <stdio.h>
void bubbleSort(int *,int);

int main(){
  int i;
  int A[100],N;
  scanf("%d",&N);
  for(i = 0;i<N;i++){
    scanf("%d",&A[i]);    
  }
  bubbleSort(A,N);
  return 0;
}

void bubbleSort(int A[],int N){
  int i,j,k,tmp;
  int flag=1;
  i=0;
  while(flag!=0){
    flag=0;
    for(j=N-1;j >= 1;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag=1;
	i++;
      }
    }
  }
    
    for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1) printf(" ");
    }
    printf("\n");
    printf("%d\n",i);
  
}





