#include <stdio.h>
#define N 100
int main()
{
  int mini,i,j,k[N],kin,gensui,cnt;
  scanf("%d",&kin);

for(i=0;i<kin;i++)
{
    scanf("%d",&k[i]);
}

for(i=0;i<kin-1;i++)
{
  mini=i;
  for(j=i;j<kin;j++)
  {
  if(k[j]<k[mini])
  mini=j;
  }

gensui=k[i];
k[i]=k[mini];
k[mini]=gensui;

if(i!=mini)
cnt++;
}

for(i=0;i<kin;i++)
{
  if(i>0)
  printf(" ");

  printf("%d",k[i]);
}

printf("\n");
printf("%d\n",cnt);

return 0;
}

