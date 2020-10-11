#include<stdio.h>
#define MAX 100000



struct Card{
  char s;
  int v;
};

struct Card L[MAX], R[MAX];

void merge(struct Card A[], int n, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;



  for( i = 0 ; i < n1 ; i++ ){
    L[i] = A[left + i];
  }



  for( i = 0 ; i < n2 ; i++ ){
    R[i] = A[mid + i];
  }
  L[n1].v = R[n2].v = 2000000000;
  i = j = 0;
  for( k = left ; k < right ; k++){



    if( L[i].v <= R[j].v ){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void m_s(struct Card A[], int n, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    m_s(A, n, left, mid);
    m_s(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}



int partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card t, x;

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

void quick(struct Card A[], int n ,int p, int r){
  int q;
  if( p < r ){

    q = partition(A, n, p, r);

    quick(A, n, p, q-1);
    quick(A, n, q+1, r);
  }
}

int main(){
  int i, n, v;
  struct Card A[MAX], B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d", &n);
  for( i = 0 ; i < n ; i++){
    scanf("%s %d", S, &v);
    A[i].s = B[i].s = S[0];
    A[i].v = B[i].v = v;
  }
  m_s(A, n, 0, n);
  quick(B, n, 0, n-1);

  for( i = 0 ; i < n ; i++){
    if( A[i].s != B[i].s ) stable = 0;
  }

  if( stable == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n", B[i].s, B[i].v);
  }
  return 0;
}

