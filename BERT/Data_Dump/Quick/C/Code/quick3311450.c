#include <stdio.h>
#include <stdlib.h>
#define INFTY 2147483647


typedef struct{
  char mozi;
  int suzi;
}tramp;

void mergeSort(tramp *,int,int);
void merge(tramp *,int,int,int);
int judge(tramp *,tramp *,int);

void quicksort(tramp *,int,int);
int partition(tramp *,int,int);
void swapping(tramp *,tramp *,tramp *);
  
int main(){
  int n,i,ju;
  tramp *A,*S;

  scanf("%d",&n);
  A = (tramp *)malloc(n * sizeof(tramp));
  S = (tramp *)malloc(n * sizeof(tramp));

  for(i = 1;i < n + 1;i++){
    scanf(" %c %d",&A[i].mozi,&A[i].suzi);
      S[i - 1].mozi = A[i].mozi;
      S[i - 1].suzi = A[i].suzi;
  }

  //   S = A;//kokookasisou

     quicksort(A,0,n);

     mergeSort(S,0,n);

  ju = judge(A,S,n);
  
  if(ju == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 1;i < n + 1;i++)  printf("%c %d\n",A[i].mozi,A[i].suzi);

  free(A);
  free(S);
  return 0;
}

void quicksort(tramp *A,int p,int r){
  int q;
  if(r > p){
    q = partition(A,p,r);
    quicksort(A,p,q - 1);
    quicksort(A,q + 1,r);
  }
}

int partition(tramp *A,int p,int n){
  int i,j;
  tramp x,hako;
  x = A[n];
  i = p - 1;
  for(j = p;j < n;j++){
    if(A[j].suzi <= x.suzi){
      i += 1;
      swapping(&A[i],&A[j],&hako);
    }
  }
  swapping(&A[i + 1],&A[n],&hako);
  
  return i + 1;
}

void swapping(tramp *A,tramp *AA,tramp *dust){
  *dust = *A;
  *A = *AA;
  *AA = *dust;
}






int judge(tramp *A,tramp *B,int n){
  int i,num = 1;
  for(i = 1;i < n + 1;i++){
    // printf("%c %d vs %c %d\n",A[i].mozi,A[i].suzi,B[i - 1].mozi,B[i - 1].suzi);
    if(
(A[i].mozi != B[i - 1].mozi) || (A[i].suzi != B[i - 1].suzi)) num = 0;
  }
  return num;
}











void merge(tramp *A,int left,int mid,int right){
  int i,j,k,n1,n2;
  tramp *L,*R;
  n1 = mid - left;
  n2 = right - mid;
  // L[0...n1], R[0...n2] を生成
  L = (tramp *)malloc((n1 + 1) * sizeof(tramp));
  R = (tramp *)malloc((n2 + 1)* sizeof(tramp));
  for(i = 0;i < n1;i++){
    L[i].suzi = A[left + i].suzi;
    L[i].mozi = A[left + i].mozi;
  }
  for(i = 0;i < n2;i++){
    R[i].suzi = A[mid + i].suzi;
    R[i].mozi = A[mid + i].mozi;
  }
  L[n1].suzi = INFTY;
  R[n2].suzi = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i].suzi <= R[j].suzi){
      A[k].suzi = L[i].suzi;
      A[k].mozi = L[i].mozi;
      i = i + 1;
    }
    else{
      A[k].suzi = R[j].suzi;
      A[k].mozi = R[j].mozi;
      
      j = j + 1;
    }
  }
}

void mergeSort(tramp *A,int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

