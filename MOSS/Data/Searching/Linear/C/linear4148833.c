#include<stdio.h>
#define N 10000

int main(){
  int i, j, n, q, a, A[N], count=0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &a);
    for(j=0; j<n; j++){
      if(a == A[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}

