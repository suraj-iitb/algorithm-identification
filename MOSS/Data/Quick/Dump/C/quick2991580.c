#include<stdio.h>
#include<stdlib.h>

#define INFTY 1000000001

typedef struct{
  char mark;
  int num;
}Card;

int count=0;

void quicksort(Card [], int, int);
int partition(Card [], int, int);
void swap(Card *, Card *);
void merge(Card [],int,int,int);
void mergeSort(Card [],int,int);

int main(){
  Card *A, *B;
  int max=0, stb=1, n;
  int i;

  scanf("%d",&n);

  A = (Card *)malloc(n * sizeof(Card));
  B = (Card *)malloc(n * sizeof(Card));
 
  for(i=0; i<n; i++){
    scanf(" %c %d",&A[i].mark ,&A[i].num);
    B[i] = A[i];
    
    if(max < A[i].num)
      max = A[i].num;
  }
  
  quicksort(A, 0, n-1);
  mergeSort(B, 0, n);

  for(i=0; i<n; i++){
    if(A[i].mark != B[i].mark)
      stb = 0;
  }

  if(stb)
    printf("Stable\n");
  else
    printf("Not stable\n");

  for(i=0; i<n; i++)
    printf("%c %d\n", A[i].mark, A[i].num);

  free(A);
  free(B);
  return 0;
}

void quicksort(Card A[], int p, int r){
  int q;
  
  if(p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partition(Card A[], int p, int r){
  int x;
  int i, j;
  
  x = A[r].num;
  i = p-1;

  for(j=p; j<r; j++){
    if(A[j].num <= x){
      i++;
      swap(&A[i], &A[j]);
    }
  }

  swap(&A[i+1], &A[r]);
  return i+1;
}

void swap(Card *a, Card *b){
  Card tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void merge(Card A[],int l,int m,int r){
  Card *L, *R;
  int n1, n2;
  int i, j, k;
  
  n1 = m-l;
  n2 = r-m;

  L = (Card *)malloc((n1+1) * sizeof(Card));
  R = (Card *)malloc((n2+1) * sizeof(Card));

  for(i=0; i<n1; i++)
    L[i] = A[l+i];

  for(i=0; i<n2; i++)
    R[i] = A[m+i];

  L[n1].num = INFTY;
  R[n2].num = INFTY;

  i = j = 0;
  for(k=l; k<r; k++){
    if(L[i].num <= R[j].num){
      A[k] = L[i];
      i++;
      count++;
    }
    
    else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
  
  free(L);
  free(R);
  return;
}

void mergeSort(Card A[],int l,int r){
  int m;
  
  if(l+1 < r){
    m = (l+r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

