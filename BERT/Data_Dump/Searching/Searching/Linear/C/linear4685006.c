#include<stdio.h>
#define MAX 1000000

int main(){
  int i, j, n, q, count=0, S[MAX],T[MAX], r=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(S[i] == T[j]) {
	count++;
        if(r < S[i]){
          r = S[i];
            }
        break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

