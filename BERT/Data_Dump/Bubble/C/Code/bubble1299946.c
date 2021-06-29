#include<stdio.h>


int main(){
  
  int A[100],N,i,flag,n,x,count=0;
  
  scanf("%d",&n);
  
  for(i=0 ; i<n ; i++)
    {
      scanf("%d",&A[i]);
    }
  
  flag =1;
  while(flag!=0)
    {
      flag=0;
      for(i=n-1 ; i>0 ; i--)
	{
	  if( A[i] < A[i-1])
	    {
	      x=A[i];
	      A[i] = A[i-1];
	      A[i-1]=x;
	      flag=1;
	      count++;
	    }
	}
    }
  for(i=0 ; i<n ; i++){
    printf("%d",A[i]);
    if( i == n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
