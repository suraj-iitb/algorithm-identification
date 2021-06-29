#include <stdio.h>
int main()
{
  int a,count=0,i,j,k=0,n[100],swap=0;
  scanf("%d",&a);
  for(i=0;i<a;i++)
    {
      scanf("%d",&n[i]);
    }

  for(j=0;j<=a-1;j++){
    for(k=a-1;k>=j+1;k--){
      if(n[k]<n[k-1]){
	swap=n[k];
	n[k]=n[k-1];
	n[k-1]=swap;
	count++;
      }
    }
  }
  for(i=0;i<a-1;i++)
    {
      printf("%d ",n[i]);
    }
  printf("%d",n[a-1]);
  printf("\n%d\n",count);
  return 0;
}
