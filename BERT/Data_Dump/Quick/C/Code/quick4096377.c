#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100001
#define INFINITY 1000000001

typedef struct{
  char P;
  int number;
}Card;

void mergeSort(Card *, int, int);
void merge(Card *, int, int, int);
int partition(int, int);
void quicksort(int ,int);

Card M[MAX], C[MAX];//構造体変数

int main(){
  int i, n;
  int flag = 1, count = 0;
  Card temp;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf(" %c%d", &C[i].P, &C[i].number);
  }

  //マージソートで安定な配列を確保！
  for(i = 0; i < n; i++){
    M[i] = C[i];
  }
  mergeSort(M, 0, i);

  quicksort(0, n-1);

  for(i = 0; i < n; i++){
      if(M[i].P == C[i].P){
          count++;
      }else{
          printf("Not stable\n");
          break;
      }

      if(count == n) printf("Stable\n");
  }

  for(i = 0; i < n; i++){
      printf("%c %d\n", C[i].P, C[i].number);
  }

  return 0;
}

void quicksort(int p,int r){
  int q;

  if(p < r){
    q = partition(p, r);
    quicksort(p, q - 1);
    quicksort(q + 1, r);
  }
}


int partition(int p, int r){
  int i, j;
  int x;
  Card temp;

  x = C[r].number;
  i = p - 1;

  for(j = p; j <= r - 1; j++){
    if(C[j].number <= x ){
      i = i + 1;
      temp = C[i];
      C[i] = C[j];
      C[j] = temp;
    }
  }

  temp = C[i + 1];
  C[i + 1] = C[r];
  C[r] = temp;

  return i + 1;
}

void merge(Card *M,int  left,int mid,int right){
  int i, j, k, n1, n2;
  Card L[250001],R[250001];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i <= n1-1; i++){
    L[i] = M[left + i];//L[0...n1]を作成中なう
  }

  for(i = 0;i <= n2-1; i++){
    R[i] = M[mid + i];//R[0...n2]を作成中なう
  }

  L[n1].number = INFINITY;
  R[n2].number = INFINITY;

  i = 0;
  j = 0;

  for(k = left;k <= right-1; k++){
    if(L[i].number <= R[j].number){
      M[k] = L[i];
      i = i + 1;
    }else{
      M[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(Card *M,int left,int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(M, left, mid);
    mergeSort(M, mid, right);
    merge(M, left, mid, right);
  }
}

