#include<stdio.h>
#define N 100

int main()
{
  int A[1000],i,j,k,num,key;

  while(1)
    {
      scanf("%d", &num);
      if(num >= 0 && num <= N) break;
    }
  
  for(i=0;i<num;i++)
    {
      scanf("%d", &A[i]);
    }

  //表示文(1行目)
  for(k=0;k<num;k++)
	{
	  if(k<num-1) printf("%d ",A[k]);
	  else printf("%d\n",A[k]);
    }
  
  for(i=1;i<num;i++)
    {      
      key = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > key)
	{
	  A[j + 1] = A[j];
	  j--;
	  A[j + 1] = key;
	}

      //表示文(2行目以降)
      for(k=0;k<num;k++)
	{
	  if(k<num-1) printf("%d ",A[k]);
	  else printf("%d\n",A[k]);
	}
    }
  
  return 0;
}

