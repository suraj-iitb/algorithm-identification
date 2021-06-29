#include <stdio.h>
#define n_max 10000
#define q_max 500
#define S_MAX 1000000000
#define T_MAX 1000000000

int main(){
  int n, i, j, q, count=0;
  int S[n_max], T[q_max], c[q_max];

  scanf("%d",&n);//n個の数列

  for(i=0;i<n;i++){//数列の要素
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);//q個の数
  
  for(i=0;i<q;i++){//数列の要素
    scanf("%d",&T[i]);
  }

  
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
      if(S[i]==T[j]){
	count++;
        T[j]=-1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

