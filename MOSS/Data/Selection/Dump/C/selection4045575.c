#include<stdio.h>
void sellection(int*,int);
int c=0;

int main()
{

  int n,i;
  
  scanf("%d",&n);
  int A[n];

  for(i=0;i<n;i++){
  scanf("%d",&A[i]);
   }

 sellection(A,n);
 
  for(i=0;i<n;i++)
  {
  if(i==0)printf("%d",A[i]);
  else printf(" %d",A[i]);
  }
  printf("\n%d\n",c);

  return 0;
  
}

void sellection(int *A,int N)
{
  int i,minj,j,a;
  for(i=0;i<N;i++)
  {
  minj=i;
      for(j=i;j<N;j++)
      {
      if(A[j]<A[minj])
      {
      minj=j;
      }
      }
      
      if(i!=minj)
      {
      
      a=A[i];
      A[i]=A[minj];
      A[minj]=a;
      
      c++;
      }
    
  
  }
  
}

