#include<stdio.h>
#include<stdlib.h>
#define MAX 500000
#define INF 2000000000
typedef struct Cards{
  int number;
  char mark;
}card;
void quickSort(int, int);
int partition(int, int);
void swapCard(card *, card *);
void merge(int, int, int, int);
void mergeSort(int, int, int);
int isStable(void);
card L[MAX/2+2], R[MAX/2+2], *M, *Q;
int n;
int main(){
  int i, num;
  char c;
 
  scanf("%d",&n);
  Q = malloc(sizeof(card) * n);
  M = malloc(sizeof(card) * n);
  for (i = 0; i < n; i++) {
    scanf(" %c %d", &c, &num);
    M[i].number = num;
    M[i].mark = c;
    Q[i].number = num;
    Q[i].mark = c;
  }
  quickSort(0,n-1);
  mergeSort(n, 0, n);
  if ( isStable() ){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }
  for (i = 0; i < n; i++) {
    printf("%c %d\n", Q[i].mark, Q[i].number);
  }
  return 0;
}
void quickSort(int p, int r){
  int q;
  if ( p < r ) {
    q = partition(p, r);
    quickSort(p, q-1);
    quickSort(q+1, r);
  }
  return ;
}
int partition(int p, int r){
  int i, j, key;
  key = Q[r].number;
  j = p-1;
  for (i = p; i < r; i++) {
    if ( Q[i].number <= key ) {
      j++;
      swapCard(&Q[i], &Q[j]);
    }
  }
  swapCard(&Q[j+1], &Q[r]);
  return j+1;
}
void mergeSort(int n, int left, int right){
  int mid;
  if( left + 1 < right ) {
    mid = (left + right) / 2;
    mergeSort(n, left, mid);
    mergeSort(n, mid, right);
    merge(n, left, mid, right);
  }
  return;
}
void merge(int n, int left, int mid, int right){
  int i, j, k, n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++) {
    L[i] = M[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = M[mid + i];
  }
  L[n1].number = INF;
  R[n2].number = INF;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    if ( L[i].number <= R[j].number ) {
      M[k] = L[i];
      i++;
    } else {
      M[k] = R[j];
      j++;
    }
  }
}
void swapCard(card *Q1, card *Q2){
  card tmp;
  tmp = *Q1;
  *Q1 = *Q2;
  *Q2 = tmp;
  return ;
}
int isStable(void){
  int i, j;
  for (i = 0;i < n; i++) {
    if ( Q[i].mark != M[i].mark) {
      return 0;
    }
  }
  return 1;
}
