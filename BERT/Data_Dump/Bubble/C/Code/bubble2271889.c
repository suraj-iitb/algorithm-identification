#include<stdio.h>
static const int N = 100;

void bubbleSort(int *A,int n){
  int i,j,key,count=0;
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>0;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      key=A[j];
	      A[j]=A[j-1];
	      A[j-1]=key;
	      count++;
	    }
	}
    }
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d",A[i]);
  printf("\n%d\n",count);
}
        
int main(){
  int i,n;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  bubbleSort(A,n);
 
  return 0;
}
