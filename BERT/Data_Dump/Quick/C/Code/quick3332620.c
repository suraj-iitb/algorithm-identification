#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define INFTY 1000000001
typedef struct{
  int number;
  char mark;
}card;

card L[MAX/2+2], R[MAX/2+2], M[MAX], Q[MAX];
int n;

void swapCard(card *x, card *y){
  card tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
  return ;
}
void merge(int left, int mid, int right){
  int i, j, k, n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++) L[i] = M[left + i];
  for (i = 0; i < n2; i++)R[i] = M[mid + i];
  L[n1].number = INFTY;
  R[n2].number = INFTY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    if ( L[i].number <= R[j].number ) M[k] = L[i++];
    else M[k] = R[j++];
    }
}

void mergeSort(int left, int right){
  if( left + 1 < right ) {
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
  return;
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

void quickSort(int p, int r){
  if ( p < r ) {
    int q = partition(p, r);
    quickSort(p, q-1);
    quickSort(q+1, r);
  }
  return ;
}

int isStable(void){
  int i;
  for (i = 0;i < n; i++) {
    if ( Q[i].mark != M[i].mark) {
      return 0;
    }
  }
  return 1;
}

int main(){
  int i, num;
  char c;
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf(" %c %d", &c, &num);
    M[i].number = Q[i].number = num;
    M[i].mark = Q[i].mark = c;
  }
  quickSort(0,n-1);
  mergeSort(0, n);
  if ( isStable() ==1)printf("Stable\n");
  else printf("Not stable\n");
  for (i = 0; i < n; i++) printf("%c %d\n", Q[i].mark, Q[i].number);
  return 0;
}

