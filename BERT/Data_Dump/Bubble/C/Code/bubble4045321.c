#include<stdio.h>
void bubblesort(int*,int);
int c=0;

int main()
{

  int n,i;
  
  scanf("%d",&n);
  int A[n];

  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
   }

 bubblesort(A,n);
 
  for(i=0;i<n;i++)
  {
  if(i==0)printf("%d",A[i]);
  else printf(" %d",A[i]);
  }
  printf("\n%d\n",c);

  return 0;
  
}

void bubblesort(int *A,int N)
{
  int flag=1,a,j;
  
  while(flag) 
    {
    
      flag=0;
      for(j=N-1;j>=1;j--)	
      {

	  if (A[j]<A[j-1])
	    {
	      a=A[j];
	      A[j]=A[j-1];
	      A[j-1]=a;
	      flag=1;
	      c++;
	    }
	  
	  }
      
    }

  
}

