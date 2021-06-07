#include<stdio.h>

int main(){

  int i, j, n, q, cnt=0;

  scanf("%d", &n);

  int S[n];

  for(i=0;i<n;i++) scanf("%*c%d", &S[i]);

  scanf("%d", &q);

  int T[q];

  for(i=0;i<q;i++) scanf("%*c%d", &T[i]);

  for(i=0;i<q;i++){

    for(j=0;j<n;j++){

      if(S[j]==T[i]){

	cnt++;

	break;

      }

    }

  }

  printf("%d\n", cnt);

  return 0;

}

