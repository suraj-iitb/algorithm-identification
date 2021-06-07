#include <stdio.h>
#include <stdlib.h>

int main (){
  
  int n, q, cnt=0, r, l = 0, m;
  scanf("%d", &n);
  r = n;
  int *A = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  int *B = (int *)malloc(sizeof(int) * q);
  for (int i = 0; i < q; i++){
    scanf("%d", &B[i]);
  }

  /*
  for (int i = 0; i < q; i++){
    for (int j = 0; j < n; j++){
      if (A[j] == B[i]) {
	cnt++;
	break;
      }
    }
  }
  */

  // kokokara

  int i = 0;
  int c = 0;
  while(i < q){
    m = (r + l)/ 2;
    //printf("l %d, r %d, m %d, A %d, B %d\n", l, r, m, A[m], B[i]);
    if (A[m] == B[i]) {
      cnt++;
      l = 0;
      r = n;
      i++;
      //printf("A\n");
      continue;
    } else if (A[m] > B[i]){
      r = m;
      //printf("B\n");
    } else if (A[m] < B[i]){
      l = m + 1;
      //printf("C\n");
    }
    if (l >= r){
      l = 0;
      r = n;
      i++;
      //printf("D\n");
    }
  }
  
  printf("%d\n", cnt);

  free(A);
  free(B);
  
  return 0;
}

