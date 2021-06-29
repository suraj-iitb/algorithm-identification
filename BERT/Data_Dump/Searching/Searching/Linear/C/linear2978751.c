#include <stdio.h>

int main(){
  int i,j,count=0,n,q,s[10000],t[500];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

