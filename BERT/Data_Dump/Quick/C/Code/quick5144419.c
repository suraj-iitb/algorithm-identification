#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000005
#define TRUE 1
#define FALSE -1

typedef struct Card{
  char suit;
  int number;
}Card;

void quickSort(Card*, int, int);
int partition(Card*, int, int);
void merge(Card*, int, int ,int);
void mergeSort(Card*, int, int);
int isStable(Card*, Card*, int);

Card* card;

int main(){
  int n, i, judge;
  Card* original;

  scanf("%d", &n);
  card = malloc(sizeof(Card)*n);
  original = malloc(sizeof(Card)*n);

  for(i = 0; i < n; i++){
    scanf(" %c ", &card[i].suit);
    original[i].suit = card[i].suit;
    scanf("%d", &card[i].number);
    original[i].number = card[i].number;
  }

  quickSort(card, 0, n-1);
  mergeSort(original, 0, n);
  judge = isStable(original, card, n);

/*
  printf("merge sort = \n");
  for(i = 0; i < n; i++){
    printf("%c %d\n", original[i].suit, original[i].number);
  }
  printf("\n\n");
*/
  if(judge == FALSE){
    printf("Not stable\n");
  }
  else{
    printf("Stable\n");
  }


  for(i = 0; i < n; i++){
    printf("%c %d\n", card[i].suit, card[i].number);
  }

  return 0;
}

void quickSort(Card* A, int p, int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int partition(Card* A, int p, int r){
  int i, j, x;
  Card temp;

  x = A[r].number;
  i = p - 1;
  for(j = p; j <= r - 1; j++){
    if(A[j].number <= x){
      i = i + 1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i+1;
}

void merge(Card* A, int left, int mid, int right){
  int n1, n2, i, j, k;
  Card L[100001];
  Card R[100001];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1].number = MAX;
  R[n2].number = MAX;
  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    if(L[i].number <= R[j].number){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(Card* A, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int isStable(Card* merge_sorted, Card* quick_sorted, int n){
  int i;
  for(i = 0; i < n; i++){
    if(merge_sorted[i].suit != quick_sorted[i].suit){
      return FALSE;
    }
  }
  return TRUE;
}
