#include<stdio.h>
#define N 100

int main()
{
  int num,i,v,j,k,A[1000];
  scanf("%d",&num);         //数列の長さ

  for(i=0;i<num;i++)
    {
      scanf("%d",&A[i]);
    }


  for(i=0;i<num;i++)
    {
      v = A[i];
      j = i-1;
      while(j>=0 && A[j]>v)
	{
	  
	  A[j+1] = A[j];
	  j--;
	  A[j+1] = v;
	  
	}
      for(k=0;k<num;k++)
	{
	  if(k == num-1)printf("%d",A[k]);
	  else printf("%d ",A[k]);
	}
     
        printf("\n");
    
    }
  
  
  return 0;
}

