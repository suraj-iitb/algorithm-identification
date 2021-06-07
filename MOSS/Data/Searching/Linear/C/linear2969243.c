#include <stdio.h>
 
int main()
{
  int n,q,i,x,j;
  int array_n[10000];
  int array_q[10000];
  int count=0;
 
  for(i=0;i<100;i++){
    array_n[i]=0;
    array_q[i]=0;
  }
 
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&array_n[i]);
  }
 
  scanf("%d",&q);
  for (i=0;i<q;i++){
    scanf("%d",&x);
    for (j=0;j<n;j++){
      if (array_n[j]==x){
        count++;
        break;
      }
    }
  }
 
  printf("%d\n",count);
 
  return 0;
}

