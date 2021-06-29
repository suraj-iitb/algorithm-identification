#include<stdio.h>

int main(){
  
  int A[100],i,minj,n,j,x,count=0;
  
  scanf("%d",&n);
  
  for(i=0 ; i<n ; i++)
    {
      scanf("%d",&A[i]);
    }
  
  for(i=0 ; i<n ; i++)
    {
      minj = i;
      for(j=i ; j<n ; j++)
	{
	  if(A[j] < A[minj]){
	    minj=j;
	  }
	}
      x=A[i];
      A[i]=A[minj];
      A[minj]=x;
      if(minj != i)count++;
    }
  
  for(i=0 ; i<n ; i++){
    printf("%d",A[i]);
    if( i != n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
