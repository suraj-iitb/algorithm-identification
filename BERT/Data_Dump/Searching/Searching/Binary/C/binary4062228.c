#include <stdio.h>
#define N 100000
int kansu(int);

int a[N],b;

int main()
{
  int i,c,d,e=0;
  scanf("%d",&b);
  for(i=0;i<b;i++)
    {
      scanf("%d",&a[i]);
    }
  scanf("%d",&c);
  for(i=0;i<c;i++)
    {
      scanf("%d",&d);
      if(kansu(d))e++;
    }
  printf("%d\n",e);
  return 0;
}

int kansu(int x)
{
  int re=0,ra=b,su;

  while(re<ra)
    {
      su=(re+ra)/2;
      if(x>a[su])re=su+1;
      if(x<a[su])ra=su;
      else if(x==a[su])return 1;
    }
  return 0;
}

