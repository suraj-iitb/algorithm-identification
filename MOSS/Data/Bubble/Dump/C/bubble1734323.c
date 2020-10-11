#include<stdio.h>
int bubblesort(int A[100],int n);
int A[100],out=0;

int main()
{
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubblesort(A,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
    printf("%d\n",A[n-1]);
  printf("%d\n",out);
  return 0;
}

int bubblesort(int A[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1])
      {
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
   out++;
    }
    }
  }
}
