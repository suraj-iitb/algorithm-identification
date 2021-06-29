#include <stdio.h>
#include <string.h>

#define N 131072

typedef struct {
  char suit;
  int num;
} card_t;

card_t A[N], C[N];

void swap(char *x, char *y, int *p, int *q) {
  char tmpc;
  int tmpi;

  tmpc = *x;
  *x = *y;
  *y = tmpc;

  tmpi = *p;
  *p = *q;
  *q = tmpi;
}

int partition(int p, int r) {
  int i, j, x;

  x = A[r].num;
  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j].num <= x) {
      i++;
      swap(&A[i].suit, &A[j].suit, &A[i].num, &A[j].num);
    }
  }
  swap(&A[i + 1].suit, &A[r].suit, &A[i + 1].num, &A[r].num);
  return i + 1;
}

void quickSort(int p, int r) {
  int q;
  
  if (p < r) {
    q = partition(p, r);
    quickSort(p, q - 1);
    quickSort(q + 1, r);
  }
}

int isStable(int n) {
  int i, j, stabFlg = 1;
  
  for (i = 0; i < n; i++) {
    if (A[i].num == A[i + 1].num) {
      for (j = 0; j < n; j++) {
	if (A[i].num == C[j].num) {
	  if (A[i].suit != C[j].suit) {
	    stabFlg = 0;
	    return stabFlg;
	  }
	  else {
	    if (A[i].num != A[i + 1].num)
	      break;
	    i++;
	  }
	}
      }
    }
  }
  return stabFlg;
}

int main(void) {
  int i, n;

  memset(A, 0, sizeof(A));
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf(" %c %d", &A[i].suit, &A[i].num);
  memcpy(C, A, sizeof(A));

  quickSort(0, n - 1);
  if (isStable(n))
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  for (i = 0; i < n; i++)
    printf("%c %d\n", A[i].suit, A[i].num);

  return 0;
}
