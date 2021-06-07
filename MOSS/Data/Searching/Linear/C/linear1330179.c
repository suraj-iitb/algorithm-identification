#include<stdio.h>

int main(){
  int T[10000];
  int S[10000];
  int i,j,n,m,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&T[i]);

  scanf("%d",&m);
  for(i=0;i<m;i++) scanf("%d",&S[i]);
  
  for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
      {
      if(S[i] == T[j]){
	count++;
	break;
      }
      }
    }

  printf("%d\n",count);
  return 0;
}
