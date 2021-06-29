#include<stdio.h>
#define MAX 100001
#define INFTY 2000000000
#define INFTYc 100
int Partition(int*,int,int);
void quicksort(int*,int,int);
void merge(int*,int,int,int);
void mergeSort(int*A,int,int);
char C[MAX];
char D[MAX];
int L[MAX/2+2];
int R[MAX/2+2];
char Lc[MAX/2+2];
char Rc[MAX/2+2];

int main(){
  int i,flag;
  int n;
  int A[MAX];
  int B[MAX];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf(" %c%d",&C[i],&A[i]);
    B[i] = A[i];
    D[i] = C[i];
  }
  quicksort(A,0,n-1);
  mergeSort(B,0,n);
  for(i = 0; i < n; i++){
    flag = 1;
    if(C[i] != D[i]){
      flag = 0;
      break;
    }
  }
  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n",C[i],A[i]);
  }
  return 0;
}

int Partition(int* A,int p,int r){
  int x,i,j,tmp;
  char ctmp,y;
  x = A[r];
  y = C[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j] <= x){
      i = i + 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
      ctmp = C[i];
      C[i] = C[j];
      C[j] = ctmp;
    }
  }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    ctmp = C[i+1];
    C[i+1] = C[r];
    C[r] = ctmp;
  return i + 1;
}
void quicksort(int* A, int p, int r){
  int q;
  if(p < r){
    q = Partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

void merge(int* B,int left,int mid, int right){
  int n1,n2;
  int i,j,k;
  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = B[left + i];
    Lc[i] = D[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = B[mid + i];
    Rc[i] = D[mid + i];
  }
  L[n1] = INFTY;
  Lc[n1]= INFTYc;
  R[n2] = INFTY;
  Rc[n2] = INFTYc;
  i = 0; 
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      B[k] = L[i];
      D[k] = Lc[i];
      i = i + 1;
    }
    else{
      B[k] = R[j];
      D[k] = Rc[j];
      j = j + 1;
    }
  }
}

void mergeSort(int* B, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid, right);
  }
}
