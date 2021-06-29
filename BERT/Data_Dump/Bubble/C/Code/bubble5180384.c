#include<stdio.h>
#define N 100

int main()
{
  int flag=1,cnt=0,x,i,j,A[N],t;
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
      scanf("%d",&A[i]);
    }
  while(flag == 1){
    flag = 0;
    for(j=x-1;j>0;j--)
      {
	if(A[j]<A[j-1]){
	  t = A[j-1];
	  A[j-1] = A[j];
	  A[j] = t;
	  flag = 1;
	  cnt++;
	}
      }
  }
	    
  
  for(i=0;i<x;i++)
    {
      printf("%d",A[i]);
      if(i==x-1) break;
      printf(" ");
    }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

