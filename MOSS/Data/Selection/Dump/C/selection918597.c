#include  <stdio.h>

int main(void)
{		
  int n,i,j,temp,x[100],count=0,mini;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for (i=0;i<n;i++) {
    mini=i;
    for (j=i;j<n;j++) {
      if (x[j]<x[mini]) {
	mini=j;
      }
    }
    temp = x[i];        
    x[i] = x[mini];
    x[mini]= temp;
    if(x[i]!=x[mini])count++;
  }	
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",x[i]);
    else
      printf("%d ",x[i]);
  }
  printf("%d\n",count);
  return 0;
}
