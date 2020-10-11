#include<stdio.h>
#define MAX 100000
#define SENTI 2000000000

struct Card{
  char pic;
  int num;
};

struct Card L[MAX / 2 + 2];
struct Card R[MAX/ 2 + 2];

void Merge(struct Card *, int, int, int, int);
void mergeSort(struct Card *, int, int, int);
int Prtition(struct Card *, int, int, int);
void QuickSort(struct Card *, int, int, int);

int main(){
  int n, i, value;
  int stable = 1;
  char P[10];
  struct Card A[MAX], B[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%s %d",P,&value);
    A[i].pic = B[i].pic = P[0];
    A[i].num = B[i].num = value;
  }

  mergeSort(A,n,0,n);
  QuickSort(B,n,0,n-1);

  for(i = 0 ; i < n ; i++){
    if(A[i].pic != B[i].pic) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i < n ; i++){
    printf("%c %d\n",B[i].pic,B[i].num);
  }

  return 0;
}

void Merge(struct Card A[], int n, int l, int m, int r){
  int n1, n2, i, j, k;

  n1 = m - l;
  n2 = r - m;
  for(i = 0 ; i < n1 ; i++) L[i] = A[l + i];
  for(i = 0 ; i < n2 ; i++) R[i] = A[m + i];
  L[n1].num = R[n2].num = SENTI;

  i = 0;
  j = 0;
  for(k = l ; k < r ; k++){
    if(L[i].num <= R[j].num) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(struct Card A[], int n, int l, int r){
  int m;
  if(l + 1 < r){
    m = (l + r) / 2;
    mergeSort(A, n, l, m);
    mergeSort(A, n, m, r);
    Merge(A, n, l, m, r);
  }
}

int Partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card x, tmp;

  x = A[r];
  i = p - 1;
  for(j = p ; j < r ; j++){
    if(A[j].num <= x.num){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp;
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

