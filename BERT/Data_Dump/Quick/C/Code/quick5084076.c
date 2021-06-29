#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char c;
  int num;
} CARD;

void quickSort(CARD *, int, int);
int partition(CARD *, int, int);
int check(CARD *, CARD *, int);

int main(){
  CARD *in, *A;
  int i, n;

  scanf("%d", &n);

  in = (CARD *)malloc(n * sizeof(CARD));
  A = (CARD *)malloc(n * sizeof(CARD));

  for(i = 0; i < n; i++){
    scanf(" %c%d", &in[i].c, &in[i].num);
    A[i] = in[i];
  }

  quickSort(A, 0, n-1);

  if(check(in, A, n) == 1) printf("Stable\n");
  else if(check(in, A, n) == 0) printf("Not stable\n");

  for(i = 0; i < n; i++) printf("%c %d\n", A[i].c, A[i].num);
  
  return 0;
}

int partition(CARD *A, int p, int r){
  int i, j;
  CARD x, s;
  x = A[r];
  i = p-1;
  for(j = p; j < r; j++){
    if(A[j].num <= x.num){
      i++;
      s = A[i];
      A[i] = A[j];
      A[j] = s;
    }
  }
  s = A[i+1];
  A[i+1] = A[r];
  A[r] = s;
  return i+1;
}

void quickSort(CARD *A, int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int check(CARD *in, CARD *A, int n){
  int i, j, k;

  for(i = 0; i < n; i++){
    k = 0;
    while(1){
      if(i+1 == n) return 1;
      if(A[i].num == A[i+1].num){
	for(j = k; j < n; j++){
	  if(A[i].num == in[j].num){
	    if(A[i].c != in[j].c) return 0;
	    k = j+1;
	    break;
	  }
	}
	i++;
      }
      else break;
    }
  }
  
}

