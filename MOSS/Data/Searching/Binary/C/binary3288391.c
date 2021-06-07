#include <stdio.h>
#define N_MAX 100000
#define Q_MAX 50000

int main(){
  int n,q,S[N_MAX],T[Q_MAX],l,m,r,i,j,cnt=0;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }
 
  for(i=0;i<q;i++){
    l = 0;
    r = n;
    while(l < r){
      m = (l + r)/2;
      if(T[i] == S[m]){
	cnt++;
	break;
      }
      else if(T[i] > S[m])l = m + 1;
      else if(T[i] < S[m])r = m;
    }
  }


  printf("%d\n",cnt);
  return 0;
  
}

