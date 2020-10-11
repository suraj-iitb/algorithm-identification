#include<stdio.h>
#define N 100
int main(){
  int kosuu,i,j,A[N],count = 0,a,b,minj;
  
  scanf("%d",&kosuu);
  for(i = 0;i < kosuu ; i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<kosuu-1;i++)
    {
      minj = i;
      for(j = i;j<kosuu;j++)
      {
      if(A[j] < A[minj])
	{
	  minj = j ;
	 
	}
      }
      a = A[i];
      b = A[minj];
      A[i] = b;
      A[minj] = a;
      if(A[minj]==A[i])count--;
       count++;
      
    }
  for(i=0;i<kosuu-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);
	
  return 0;
}

