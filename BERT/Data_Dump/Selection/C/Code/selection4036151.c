#include<stdio.h>
void selectionSort(int[], int);
void swap(int *, int *);
int main()
{
  int N,A[100],i,minj;

  scanf("%d",&N);

  for(i=0; i<N; i++) scanf("%d",&A[i]);

  selectionSort(A,N);

  return 0;

}

void selectionSort(int A[], int N)
{
  int minj,i,j,count=0;

  for(i=0; i<N; i++)
    {
      minj=i;
      for(j=i; j<N; j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj=j;
	    
	    }
	  
	}
      if(minj!=i)
	{
	  swap(&A[i],&A[minj]);
	  count++;
	}
    }
  for(i=0; i<N; i++)
    {
      if(i!=N-1) printf("%d ",A[i]);
      else printf("%d",A[i]);
    }
  printf("\n");
  printf("%d\n",count);
}



void swap(int *a, int *b)
{
  int temp;

  temp=*a;
  *a=*b;
  *b=temp;
}

