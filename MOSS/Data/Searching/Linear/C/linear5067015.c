#include <stdio.h>
#include <stdlib.h>
#define nmax 10000
#define qmax 500
int main(){
  int i,j;
  int n,q;
  int S[nmax];
  int T[qmax];
  int count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);
  
  
  return 0;
  
}
