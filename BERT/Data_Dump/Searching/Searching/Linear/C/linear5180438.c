#include<stdio.h>
#define N 10000
#define Q 500


int main()
{
  int x,y,i,j,s[N],t[Q],t_count[Q]={};
  int multiple = -1;
  int cnt = 0;
  //入力
  
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
        scanf("%d",&s[i]);
	//printf("%d ",s[i]);
    }
  
  scanf("%d",&y);
  for(i=0;i<y;i++)
    {
      scanf("%d",&t[i]);
      //  printf("%d ",t[i]);
    }
  

  //アルゴリズム
  
   for(i=0;i<x;i++)
    {
      for(j=0;j<y;j++)
        {
	    if( s[i]== t[j]&&t_count[j]!=1 )
	    {
	      t_count[j] = 1;
	     
	      // printf(" cnt=%d si=%d tj=%d\n",cnt,s[i],t[j]);
	    }
	  }
    }

   for(i=0;i<y;i++)
     {
       if(t_count[i]==1)
	 cnt++;
     }
      

  //出力
  printf("%d\n",cnt);
  return 0;
}

