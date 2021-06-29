#include<stdio.h>
int main()
{
  int A[100];
  int n,i,j,v;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
    for(i = 0;i < n ;i++)
	{
	  if(i)
	    printf(" ");
	  printf("%d", A[i]);
	}
      printf("\n");
  
  for(i=1; i < n; i++)
    {
      v = A[i];//i番目の値をvに代入
      j = i-1;//i-1番目のindexをjに代入
      while(j >= 0 && A[j] > v)//jが正かつi番目の値がi-1番目の値より小さかったら繰り返す
	{
	  int a = A[j+1];
	  A[j+1] =  A[j];//i-1番目の値をi番目の値に
	  A[j] = a;
	  j--;//indexを1下げる
	}
      A[j+1] = v;
      for(j = 0;j < n ;j++)
	{
	  if(j)
	    printf(" ");
	  printf("%d", A[j]);
	}
      printf("\n");
    }
  return 0;
}

