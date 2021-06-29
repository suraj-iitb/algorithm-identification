#include<stdio.h>
#define N 100

int main()
{
  int cnt=0,x,i,j,A[N],minj,t,s,koukan;
  //数列の長さxと数列の値を格納する
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
      scanf("%d",&A[i]);
    }
  
  //選択ソートのメインプログラム
  for(i=0;i<x;i++)
    {
      koukan = 0;
      minj = i;
      for(j=minj+1;j<x;j++)
	{
	  if(A[j]<A[minj]) // 5 4 6 3 1 
	    {
	      minj = j;
	      koukan = 1;
	    }
	}
      t=A[minj];
      A[minj] = A[i];
      A[i]=t;
      //for(s=0;s<x;s++) printf("%d ",A[s]);
      
      //printf("\n");
      if(koukan==1)cnt++;
      //printf("cnt = %d\n",cnt);
    }
  //昇順に出力する＆交換した回数を表示する
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

