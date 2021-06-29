#include<stdio.h>

void insertionSort(int*,int);

int main()
{
  int n,i;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++)
  scanf("%d",&A[i]);

  insertionSort(A,n);
  return 0;
  
}

void insertionSort(int *A,int n)
{
  int i,j,key,p;

  for(p=0;p<n;p++)
    {
      if(p==n-1)
      printf("%d",A[p]);
      else
      printf("%d ",A[p]);
    }
      printf("\n");
  
  for(j=1;j<=n-1;j++)
    {
      key=A[j];
      /*A[j]をソート済みの列A[1..j-1]に挿入する*/
      i=j-1;

      while(i>=0&&A[i]>key)
	{
	  A[i+1]=A[i];
	  i=i-1;
	  A[i+1]=key;	  
	}
   for(p=0;p<n;p++)
     {
       if(p==n-1)
	 printf("%d",A[p]);
       else
      printf("%d ",A[p]);
     }
      printf("\n");
    }

}

