#include <stdio.h>

int main(){
  int n,m,i,j,c=0;

  scanf("%d",&n);

  int S[n];

  for(i=0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);

  int T[m];

  for(i=0; i < n; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i < n; i++){
    for(j=0; j < m; j++){
      if(S[i] == T[j]){
	T[j] = -1;
	c++;
      }
    }
  }

  printf("%d\n",c);

  return 0;
}


