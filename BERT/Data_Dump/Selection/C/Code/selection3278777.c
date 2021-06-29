#include <stdio.h>

int selectionSort(int A[],int N)
{
  int i,j,minj,count=0,temp;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[minj]>A[j]){
	minj=j;
      }
    }
	temp=A[i];
	A[i]=A[minj];
	A[minj]=temp;
	if(i!=minj){
	  count++;
	}
  }

  return count;
}
    
      
      

  
int main()
{
  int A[100],N,i,count;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  count=selectionSort(A,N);

  for(i=0;i<N;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

 
  return 0;
}
  

