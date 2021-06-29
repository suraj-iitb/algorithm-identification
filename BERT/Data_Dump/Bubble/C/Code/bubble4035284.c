#include <stdio.h>

int bubbleSort(int A[], int N)
{
  int flag=1,i,j,a,b,count=0;
  while(flag==1){
    flag=0;
    for(j=N-1;j>= 1;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	b=A[j-1];
	
	A[j]=b;
	A[j-1]=a;
	flag=1;
	count++;
      }
    }
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

  count=bubbleSort(A,N);

  for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",count);

  
  return 0;
}

