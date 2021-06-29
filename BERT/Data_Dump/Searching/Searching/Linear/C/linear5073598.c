#include<stdio.h>
int main()
{
  int i,j,n,q,count;
  count = 0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int  T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j] == T[i]){
          count++;
          break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
