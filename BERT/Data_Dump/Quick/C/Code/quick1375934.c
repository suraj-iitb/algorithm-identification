#include <stdio.h>
#define N 100000
typedef struct{
  int num;
  char mark;
  int check;
}Card;

int Partition(Card [], int, int);
void QuickSort(Card [], int, int);
void Exchange(Card *, Card *);


int main(){
  int i, j, n, flag = 0;
  char kaigyoukunn;
  Card A[N];

  // Input n
  scanf("%d%c", &n, &kaigyoukunn);// c言語改行文字の闇

  // Input A[n]
  for(i = 0; i < n; i++){
    scanf("%c%d%c", &A[i].mark, &A[i].num, &kaigyoukunn);
    A[i].check = i;
  }

  // QuickSort
  QuickSort(A, 0, n - 1);

  // Judge
  for(i = 0; i < n; i++){
    if(A[i].num == A[i + 1].num && A[i].check > A[i + 1].check && flag == 0){
      printf("Not stable\n");
      flag = 1;
      break;
    }
  }
  if(flag == 0) printf("Stable\n");

  // Output
  for(i = 0; i < n; i++) printf("%c %d\n", A[i].mark, A[i].num);

  return 0;
}

// Partition function
int Partition(Card A[], int p, int r){
  int x, i, j;
  // i is <, j is |

  // Set x, i
  x = A[r].num;
  i = p - 1;

  // Partition
  for(j = p; j < r; j++){

    if(A[j].num <= x){
      i++;
      Exchange(&A[i], &A[j]);
    }
  }
  Exchange(&A[i + 1], &A[r]);

  return i + 1;
}

// QuickSort function
void QuickSort(Card A[], int p, int r){
  int q;

  if(p < r){
    q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}

void Exchange(Card *a, Card *b){
    Card t = *a;
    *a = *b;
    *b = t;
}
