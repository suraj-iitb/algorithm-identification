#include<stdio.h>
#define MAX 1000000
#define SENTI 2000000000

struct Card{
  char p;
  int n;
};

struct Card L[MAX / 2 + 2];
struct Card R[MAX/ 2 + 2];

void Merge(struct Card *, int, int, int, int);
void mergeSort(struct Card *, int, int, int);

int Partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card x, key;

  x = A[r];
  i = p - 1;
  for(j = p ; j < r ; j++){
    if(A[j].n <= x.n){
      i++;
      key = A[i];
      A[i] = A[j];
      A[j] = key;
    }
  }
  key = A[i + 1];
  A[i + 1] = A[r];
  A[r] = key;
  return i+1;
}



void QuickSort(struct Card A[], int n, int p, int r){
  int x;

  if(p < r){
    x = Partition(A, n, p, r);
    QuickSort(A, n, p, x - 1);
    QuickSort(A, n, x + 1, r);
  }
}



int main(){
  int n, i, kati;
  int stable = 1;
  char P[10];
  struct Card A[MAX], B[MAX];

  scanf("%d",&n);
i=0;
  while(i < n){
    scanf("%s %d",P,&kati);
    A[i].p = B[i].p = P[0];
    A[i].n = B[i].n = kati;
    i++;
  }

  mergeSort(A,n,0,n);
  QuickSort(B,n,0,n-1);
i=0;
  while(i < n ){
    if(A[i].p != B[i].p) stable = 0;
    i++;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
i=0;
  while( i < n ){
    printf("%c %d\n",B[i].p,B[i].n);
    i++;
  }

  return 0;
}

void Merge(struct Card A[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;
  i=0;
  while(i < n1 ){
   L[i] = A[left + i];
   i++;
 }
 i=0;
  while(i < n2 ){
     R[i] = A[mid + i];
     i++;
   }
  L[n1].n = R[n2].n = SENTI;

  i = 0;
  j = 0;
  for(k = left ; k < right ; k++){
    if(L[i].n <= R[j].n) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(struct Card A[], int n, int left, int right){
  int m;
  if(left + 1 < right){
    m = (left + right) / 2;
    mergeSort(A, n, left, m);
    mergeSort(A, n, m, right);
    Merge(A, n, left, m, right);
  }
}

