#include <stdio.h>
int bubbleSort(int*,int);
int main(){
  int A[100],i,j,N,s;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  s=bubbleSort(A,N);

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1)break;
    printf(" ");
  }
  printf("\n");
  
  printf("%d\n",s);
  return 0;
}

int bubbleSort(int A[],int N){
  int s = 0,flag=1,i,j,tmp;
  while(flag==1){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	s++;
      }
    }
  }
  return s;
}

