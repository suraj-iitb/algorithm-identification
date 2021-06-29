#include<stdio.h>
#include<stdlib.h>

#define N 10000
#define Q 500

main(){
  int n,q,i,S[N],T[Q],U[Q],j,k=0,m;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      
      if(S[j]==T[i]){
	U[k]=S[j];	
	k++;
	for(m=0;m<k-1;m++){
	  if(U[m]==S[j]) k--;
	}
      }
    }
  }
  printf("%d\n",k);

  return 0;

}
