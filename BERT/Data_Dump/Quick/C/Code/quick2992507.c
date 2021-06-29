#include<stdio.h>
#include<stdlib.h>

#define M 100000
#define INFTY 10000000000

typedef struct{
  char mark;
  int s;
} Card;

Card A[M],B[M],D[M];
int C[M],n;

int partition(int p, int r){

  int x,i,j;
  Card k;

  x = A[r].s;
  i = p-1;

  for(j = p;j<r;j++){
    if(A[j].s <= x){
      i = i+1;
      k = A[i];
      A[i] = A[j];
      A[j] = k;
    }
  }
  k = A[i+1];
  A[i+1] = A[r];
  A[r] = k;

  return i+1;
}

void quicksort(int p,int r){

  int q;
  
  if(p<r){
    q = partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}

void merge(int left,int mid,int right){
  
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;

  Card L[n1],R[n2];
  
  for(i=0;i<n1;i++) L[i] = D[left + i];
  for(i=0;i<n2;i++) R[i] = D[mid + i];
  L[n1].s = INFTY;
  R[n2].s = INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].s <= R[j].s){
      D[k] = L[i];
      i=i+1;
    }
    else {
      D[k] = R[j];
      j = j+1;
    }
  }
}

void mergesort(int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(left, mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}

int main(){

  int i,j,k,stable = 1;
  char L;


  scanf("%d",&n);
  scanf("%c",&L);

  for(i=0;i<n;i++){
    scanf("%c",&A[i].mark);
    scanf("%d",&A[i].s);
    scanf("%c",&L);
    D[i] = A[i];
  }

  quicksort(0,n-1);

  k = D[0].s;
  for(i=1;i<n;i++){
    if(k<D[i].s) k =D[i].s;
  }

  mergesort(0,n);

  for(i=0;i<n;i++){
    if(A[i].mark != D[i].mark) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  
  for(i=0;i<n;i++){
  printf("%c %d\n",A[i].mark,A[i].s);
}
  

  return 0;
}

