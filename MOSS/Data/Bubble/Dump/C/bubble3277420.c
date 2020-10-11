#include <stdio.h>

int bubbleSort(int A[],int N)
{
  int count=0;
  int flag=1;
  int j,temp;

  while(flag==1){
    flag=0;
    
    for(j=N-1; j>=1; j--){
     
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	count++;
      }
    }
  }
  
  return count;
}




int main()
{
  int A[100],N,count=0,i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  

  count=bubbleSort(A,N);

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


































































  
  


















