#include<stdio.h>

#define N 100

int main()
{
  int kin,i,chiyonosuke,j,sotaro[N],flag=0,tmp;

  scanf("%d",&kin);
  for(i=0;i<kin; i++){
    scanf("%d",&sotaro[i]);
  }
  for(i=0;i<kin;i++)
  {
      for(j=kin-1;j>i;j--)
	{
	  if(sotaro[j]<sotaro[j-1]){
	    tmp=sotaro[j-1];
	    sotaro[j-1]=sotaro[j];
	    sotaro[j]=tmp;
	    flag++;
	  }
	}
    }
  for(i=0;i<kin;i++)
    {
      if(i>0)printf(" ");
      printf("%d",sotaro[i]);
    }
  printf("\n");
  printf("%d\n",flag);
  return 0;
}

