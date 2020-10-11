#include<stdio.h>
#include<stdlib.h>
#define N 1e5
#define M 1e9

typedef struct{
  char c;
  int e;
}card;

void merge(card*, int, int, int);
void mergesort(card*, int, int);
void quicksort(card*, int, int);
int partition(card*, int, int);
int isstable(card*, card*, int);

void merge(card A[], int left, int mid, int right){
  int i, j, k, n1=mid-left, n2=right-mid;
  card L[n1+1], R[n2+1];

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1].e=M; R[n2].e=M;

  for(i=0,j=0,k=left;k<right;k++){
    if(L[i].e<=R[j].e){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }return ;
}

void mergesort(card A[], int left, int right){
  if(left+1<right){
    int mid=(left+right)/2;

    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }return;
}

void quicksort(card *A, int p, int r){

    if(p<r){
        int q=partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }return;
}

int partition(card *A, int p, int r){

  int x=A[r].e, i=p-1, j;
  card tmp;

  for(j=p;j<r;j++){
      if(A[j].e<=x){
      i++;
      tmp=A[i]; A[i]=A[j]; A[j]=tmp;
    }
  }tmp=A[i+1]; A[i+1]=A[r]; A[r]=tmp;
  return i+1;
}

int isstable(card *A, card *B, int n){
    for(int i=0;i<n;i++){
        if(A[i].c!=B[i].c) return 0;
    }return 1;
}

int main(){
  int i, j, n;
  card *t, *a, *b;
  t = (card *)malloc(sizeof(card)*N);
  a = (card *)malloc(sizeof(card)*N);
  b = (card *)malloc(sizeof(card)*N);

  scanf("%d", &n);

  for(i=0;i<n;i++) scanf("%*c%c%d", &t[i].c, &t[i].e);

  for(i=0;i<n;i++){
    a[i]=t[i];
    b[i]=t[i];
  }

  quicksort(a,0,n-1);
  mergesort(b,0,n);

  if(isstable(a,b,n)==1) printf("Stable\n");
  else printf("Not stable\n"); 

  for(i=0;i<n;i++) printf("%c %d\n",a[i].c,a[i].e);

  return 0;
}
