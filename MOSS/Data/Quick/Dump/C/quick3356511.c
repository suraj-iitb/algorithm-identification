#include<stdio.h>
#define INFTY 2000000000
typedef struct node{
  char mark;
  int num;
}C;

int n;

void merge(C A[], int left, int mid, int right){
  int n1 = mid - left ,n2 = right - mid,i,j,k;
  C L[n1+1],R[n2+1];
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1].num =  INFTY;
  R[n2].num =  INFTY;
  i = 0; j = 0;
  for(k = left; k < right; k++){
    if(L[i].num <= R[j].num){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(C A[],int left, int right){
  int mid;
  if (left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(C A[],int p,int r){
  int i,j;
  C x,numb;
  x = A[r];
  i = p-1;
  for(j = p; j < r;j++){
    if(A[j].num <= x.num){
      i = i+1;
      numb = A[i];
      A[i] = A[j];
      A[j] = numb;
    }
  }
  numb = A[i+1];
  A[i+1] = A[r];
  A[r] = numb;
  return i + 1;
}

void quicksort(C A[],int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int main(){
  int i,nu,stable = 0;
  C A[100000],B[100000];
  char P;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf(" %c %d",&P,&nu);
    A[i].mark = P;
    B[i].mark = P;
    A[i].num = nu;
    B[i].num = nu;
  }
  mergeSort(A,0,n);
  quicksort(B,0,n-1);

  for(i = 0; i < n; i++){
    if(A[i].mark != B[i].mark) stable = 1;
  }

  if(stable == 0) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c %d\n",B[i].mark,B[i].num);
  }
  return 0;
}

