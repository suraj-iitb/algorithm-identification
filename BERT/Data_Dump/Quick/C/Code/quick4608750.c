#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
  char suit;
  int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
  for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  i = j = 0;
  for ( k = left; k < right; k++ ) {
    if ( L[i].value <= R[j].value )
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

void mergeSort(struct Card A[], int left, int right) {
  int mid;
  if ( left + 1 < right ) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(struct Card A[], int p, int r) {
  int i, j;
  struct Card t, x;
  x = A[r];
  i = p - 1;
  for ( j = p; j < r; j++ ){
    if ( A[j].value <= x.value ) {
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t;   //i番目のカードとj番目のカードを入れ替える
    }
  }
  t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;  //i+1番目のカードとr番目のカードを入れ替える
  return i + 1;
}

void quickSort(struct Card A[], int p, int r) {
  int q;
  if ( p < r ) {
    q = partition(A, p, r);
    quickSort(A, p, q - 1);    //前半グループをソート
    quickSort(A, q + 1, r);    //後半グループをソート
  }
}

int main() {
  int num_card;               // カードの枚数
  int value_card;             // カードの数字
  char S[10];                 // カードのアルファベット
  struct Card A[MAX], B[MAX]; //Aの山札，Bの山札
  int stable = 1;             // 安定であれば１

  scanf("%d", &num_card);     // カードの枚数を入力

  for (int i = 0; i < num_card; i++ ) {
    scanf("%s %d", S, &value_card); // カードのアルファベット、数字を入力
    A[i].suit = B[i].suit = S[0];          // アルファベット登録
    A[i].value = B[i].value = value_card;  // 数字登録
  }

  mergeSort(A, 0, num_card);
  quickSort(B, 0, num_card - 1);

  for (int i = 0; i < num_card; i++ )
    if ( A[i].suit != B[i].suit ) stable = 0;

  if ( stable == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  for (int i = 0; i < num_card; i++ )
    printf("%c %d\n", B[i].suit, B[i].value);

  return 0;
}
