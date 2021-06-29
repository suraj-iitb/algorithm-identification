#include <stdio.h>
int main()
{
  int a,count=0,i,j,n[100],mini=0,swap;
  scanf("%d",&a);

  for(i=0;i<a;i++)
    {
      scanf("%d",&n[i]);
    }

  for(i=0;i<a-1;i++){
    mini=i;
    for(j=i;j<a;j++){
      if(n[j]<n[mini])
	mini=j;
    }
    if(n[i]>n[mini]) count++;
    swap = n[i];
    n[i]=n[mini];
    n[mini]=swap;
  }
  for(i=0;i<a-1;i++)
    {
      printf("%d ",n[i]);
    }
  printf("%d",n[a-1]);
  printf("\n%d\n",count);
  return 0;
}
