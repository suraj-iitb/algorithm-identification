#include<stdio.h>
void bubblesort(int[], int);
void swap(int *, int *);
int main()
{
    int i,N,A[100];
    
    scanf("%d",&N);
    
    for(i=0; i<N; i++)
    {
        scanf("%d",&A[i]);
    }
    bubblesort(A,N);

    return 0;
    
}

void bubblesort(int A[], int N)
{
  int count=0,i,j;

  for(i=0; i<N; i++)
    {
      for(j=N-1; j>=i+1; j--)
	{
	 
	  if(A[j]<A[j-1])
	    {
	      swap(&A[j],&A[j-1]);
	      count++;
	    }
	  else continue;
	}
    }
  

 
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%d ",A[i]);
      else printf("%d",A[i]);

    }
  
  printf("\n");
   printf("%d\n",count);
  
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

}

