#include <stdio.h>
#define N 100000
#define S 200000000

typedef struct {
  char m;
  int v;
}Card;

Card L[N/2+2], R[N/2+2];

int partition(Card A[], int p, int r){
  int i, j, temp1v, temp2v;
  char temp1m, temp2m;
  Card x;

  x.m = A[r].m;
  x.v = A[r].v;
  i = p-1;
  for(j=p; j<r; j++){
    if(A[j].v<=x.v){
      i = i+1;
      temp1v = A[i].v;
      temp1m = A[i].m;
      A[i].v = A[j].v;
      A[i].m = A[j].m;
      A[j].v = temp1v;
      A[j].m = temp1m;
    }
  }
  temp2v = A[i+1].v;
  temp2m = A[i+1].m;
  A[i+1].v = A[r].v;
  A[i+1].m = A[r].m;
  A[r].v = temp2v;
  A[r].m = temp2m;
  return i+1;
}

void quickSort(Card A[], int p, int r){
  int q=0;

  if(p<r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void merge(Card A[], int l, int m, int r){
  int i, j, k;
  int n1 = m-l, n2 = r-m;

  for(i=0; i<n1; i++){
    L[i] = A[l+i];                                                                  
  }
  for(i=0; i<n2; i++){
    R[i] = A[m+i];                                                                  
  }
  L[n1].v = R[n2].v = S;
  i = j = 0;
  for(k=l; k<r; k++){
    if(L[i].v <= R[j].v){                                                                
      A[k] = L[i++];
    } else {
      A[k] = R[j++];                                                               
    }
  }
}

void mergeSort(Card A[], int l, int r){
    int m;
    if(l+1<r){
      m = (l+r)/2;
      mergeSort(A, l, m);
      mergeSort(A, m, r);
      merge(A, l, m, r);
    }
}

int main(){

  int i, v, n, stable=1;
  char str[10];
  Card A[N], B[N];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s %d", str, &v);
    A[i].m = str[0];
    A[i].v = v;
  }

  for(i=0; i<n; i++){
    B[i].m = A[i].m;
    B[i].v = A[i].v;                            
  }

  mergeSort(A, 0, n);
  quickSort(B, 0, n-1);

  for(i=0; i<n; i++){
    if(A[i].m != B[i].m) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++){
    printf("%c %d\n", B[i].m, B[i].v);
  }

  return 0;
}
