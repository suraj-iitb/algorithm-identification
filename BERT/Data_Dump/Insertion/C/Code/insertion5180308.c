#include<stdio.h>
#define N 100

int main()
{
  int i,j,v,s,x;
  int A[N];

  //サイズを入力(サイズの変数　x
  scanf("%d",&x);
  //配列を入力
  for(i=0;i<x;i++)
    {
      scanf("%d",&A[i]);
    }

  //並び替え
  for(i=0;i<x;i++)
    {
      v = A[i];
      j = i-1;

      while( j>=0 && v < A[j] )
	{
	  A[j+1] = A[j];
	  A[j] = v;
	  j--;
	  A[j+1] = v;
	}

      for(s=0;s<x;s++)
	{
	  printf("%d",A[s]);
	  if(s!=x-1) printf(" ");
	}
      printf("\n");
    }
  return 0;
}
	  

