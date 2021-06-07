#include <stdio.h>
int main(){
  int n,q,S[10000],T[500],i,j,count=0,a[10000],k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
	scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
	scanf("%d",&T[i]);
  for(i=0;i<q;i++){
	for(j=0;j<n;j++){
	  if(S[j]==T[i]){//同じ数を発見
		count++;
		break;
	  }
	}
  }
  printf("%d",count);
  printf("\n");
  return 0;
}

