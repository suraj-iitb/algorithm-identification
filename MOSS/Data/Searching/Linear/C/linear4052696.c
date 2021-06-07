#include <stdio.h>

#define N 20000

int main()
{
  int n,q,i,j,k,l,S[N],T[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&S[i]);
   
  scanf("%d",&q);

  for(j=0;j<q;j++) scanf("%d",&T[j]);

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i] == S[j]){
	k++;
	j = n;
      }
    }
  }

  printf("%d\n",k);

  return 0;
}

      

