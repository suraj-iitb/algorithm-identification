#include<stdio.h>
#define MAX 100000

struct Card{
  char s;
  int v;
};

struct Card L[MAX], R[MAX];

void merge(struct Card [], int, int, int, int);

void m_sort(struct Card [], int , int, int);

int partition(struct Card [], int , int , int );

void quickSort(struct Card [], int  ,int , int );


int main(){
  int i, n, v;
  //クイックソートとマージソートを比べるために二つ配列を用意する
  struct Card M[MAX], Q[MAX];
  char S[10];
  int stable = 1;

  scanf("%d", &n);
  for( i = 0 ; i < n ; i++){
    scanf("%s %d", S, &v);
    M[i].s = Q[i].s = S[0];
    M[i].v = Q[i].v = v;
  }
  //マージソート
  m_sort(M, n, 0, n);
  //クイックソート
  quickSort(Q, n, 0, n-1);

  for( i = 0 ; i < n ; i++){
    //クイックソートとマージソートを比べる
    if( Q[i].s != M[i].s ) stable = 0;
  }

  if( stable == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n", Q[i].s, Q[i].v);
  }
  return 0;
}

void merge(struct Card M[], int n, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  //左部分のマージ
  for( i = 0 ; i < n1 ; i++ ){
    L[i] = M[left + i];
  }
  // 右部分のマージ
  for( i = 0 ; i < n2 ; i++ ){
    R[i] = M[mid + i];
  }
  L[n1].v = R[n2].v = 2000000000;
  i = j = 0;
  for( k = left ; k < right ; k++){
    //　L側とR側に振り分け
    if( L[i].v <= R[j].v ){
      M[k] = L[i++];
    }
    else{
      M[k] = R[j++];
    }
  }
}

void m_sort(struct Card A[], int n, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    m_sort(A, n, left, mid);
    m_sort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

// 要素を分割し、要素の標準（ピボット）となる要素の番号を返す。
int partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card t, x;
  // t 一時避難用、x元カード保持
  x = A[r];
  i = p - 1;
  for( j = p ; j < r ; j++ ){
    if( A[j].v <= x.v ){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;
  return i + 1;
}

void quickSort(struct Card Q[], int n ,int p, int r){
  int q;
  if( p < r ){
    // 要素の分割化
    q = partition(Q, n, p, r);
    // 分割した左部分
    quickSort(Q, n, p, q-1);
    // 分割した右部分
    quickSort(Q, n, q+1, r);
  }
}

