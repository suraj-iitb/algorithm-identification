#include<stdio.h>

#define N 10000
#define Q 500
int main()
{
  int array_S[N],array_T[Q];
  int i,j,count=0,n,m;
  /*'&'忘れ注意*/
  /*数列Sの要素の個数:=n*/
  scanf("%d\n",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&array_S[i]);
    }
  /*数列Tの要素の個数:=m*/
  scanf("%d\n",&m);
  for(j=0;j<m;j++)
    {
      scanf("%d",&array_T[j]);
    }
  for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
      {
      if(array_T[i]==array_S[j])
	{
	  count++;
	  break;
	}
      }
    }
  printf("%d\n",count);
  return 0;
}
