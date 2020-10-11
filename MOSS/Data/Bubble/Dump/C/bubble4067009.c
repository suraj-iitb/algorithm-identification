#include<stdio.h>
#define N 100
int main(){
  int kosuu,i,j,A[N],flag=0,count = 0,a,b;
  


  
  scanf("%d",&kosuu);
  for(i = 0;i < kosuu ; i++){
    scanf("%d",&A[i]);
  }
  flag = 1;
  while(flag == 1)
    {
      flag = 0;
      for(j = kosuu-1 ; j >=  1 ; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      a = A[j-1];
	      b = A[j];
	      A[j] = a;
	    
	      A[j-1]=b; 
	      flag = 1;
	      count++;
	    }
	}

    }


  for(i=0;i<kosuu-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);
	
  return 0;
}

