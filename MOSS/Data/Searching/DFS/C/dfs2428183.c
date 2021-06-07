#include<stdio.h>
#define RE 100
#define RED 0
#define YELLOW 1
#define BLUE 2

int n, A[RE][RE];
int co[RE],de[RE],or[RE],t;

void dvisi(int k)
{
  int i;
  co[k]=YELLOW;
  de[k]=++t;
  for(i=0;i<n;i++)
    {
      if(A[k][i]==0)continue;
      if(co[i]==RED)
	{
	  dvisi(i);
	}
    }
  co[k]=BLUE;
  or[k]=++t;
}

void dep()
{
  int i;
  for(i=0;i<n;i++)co[i]=RED;
  t=0;
  for(i=0;i<n;i++)
    {
      if(co[i]==RED)dvisi(i);
    }
  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n",i+1,de[i],or[i]);
    }
}

int main()
{
  int i,j,ver,dnum,adver;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)A[i][j]=0;
    }

  for(i=0;i<n;i++)
    {
      scanf("%d %d",&ver,&dnum);
      ver--;
      for(j=0;j<dnum;j++)
	{
	  scanf("%d",&adver);
	  adver--;
	  A[ver][adver]=1;
	}
    }
  dep();
  return 0;
}
