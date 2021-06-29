#include <stdio.h>


int main()
{
  int n,q,x,i,j;
  int num[10000];
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&num[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&x);
    for(j=0;j<n;j++){
      if(num[j]==x){
        cnt++;
        break;
      }
    }
  }

  printf("%d\n",cnt);

  return 0;
}

