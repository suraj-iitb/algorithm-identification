#include <stdio.h>
int main(){
  int S[10000],T[500];
  int i,j,n,m,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}

