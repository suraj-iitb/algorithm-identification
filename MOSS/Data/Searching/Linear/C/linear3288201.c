#include <stdio.h>
#define N_MAX 10000
#define Q_MAX 500

int main(){
  int n,q,S[N_MAX],T[Q_MAX],i,j,cnt=0;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
    for(j = 0;j < n;j++){
      if(T[i] == S[j]){
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
  
}

