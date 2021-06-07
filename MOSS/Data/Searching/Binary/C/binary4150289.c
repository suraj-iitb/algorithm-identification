#include <stdio.h>
#define N 100001
#define Q 50001

int S[N],T[Q],n,q,i,c=0,l,r,m,k;

int main() {	
  scanf("%d",&n);

  for(i=0; i<n; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    k = T[i];
    l = 0;
    r = n;

    while(l < r){
      m = (l + r) / 2;

      if(S[m]==k){
				c++;
				break;
			}
      else if(S[m]<k){
				l = m + 1;
				continue;
			}
      else if(S[m]>k){
				r = m;
				continue;
			}
    }
  }

  printf("%d\n",c);	
	
  return 0;
}

