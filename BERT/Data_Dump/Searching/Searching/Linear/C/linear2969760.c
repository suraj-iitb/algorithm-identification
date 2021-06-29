#include<stdio.h>

#define NMAX 10000
#define QMAX 500

int main(){
  int i,j,n,q,N[NMAX],Q[QMAX],cnt=0;

  scanf("%d",&n);

  for(i=0; i<n; i++)
    scanf("%d",&N[i]);

  scanf("%d",&q);

  for(i=0; i<q; i++){
    scanf("%d",&Q[i]);
    for(j=0; j<n; j++)
      if(Q[i] == N[j]){
	cnt++;
	break;
      }
  }

  printf("%d\n",cnt);

  return 0;
}
  

