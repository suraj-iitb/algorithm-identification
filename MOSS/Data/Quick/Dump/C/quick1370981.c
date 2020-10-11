#include <stdio.h>
#include <string.h>

#define MAX 100000
#define INF (1<<29)

typedef struct{
  char mark;
  int num;
} Card;

int getMarkNumber(char);
void swap(Card*,Card*);
int partition(int,int,Card*);
void quickSort(int,int,Card*);
void merge(int,int,int,Card*);
void mergeSort(int,int,Card*);

int main(){
  int n,i,isStable;
  Card A[MAX],B[MAX];

  scanf("%d\n",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%c%d\n",&A[i].mark,&A[i].num);
    B[i] = A[i];
  }
  quickSort(0,n-1,A);
  mergeSort(0,n,B);
  isStable = 1;
  for(i = 0 ; i < n ; i++){
    if(A[i].mark != B[i].mark || A[i].num != B[i].num){
      isStable = 0;
      break;
    }
  }
  printf("%s\n",(isStable ? "Stable" : "Not stable"));
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n",A[i].mark,A[i].num);
  }
  return 0;
}

int getMarkNumber(char x){
  if(x == 'S'){ return 0; }
  if(x == 'H'){ return 1; }
  if(x == 'C'){ return 2; }
  return 3;
}

void swap(Card *a,Card *b){
  Card tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int l,int r,Card *A){
  int x = A[r].num,i = l,j;
  for(j = l ; j < r ; j++){
    if(A[j].num <= x){
      swap(&A[i++],&A[j]);
    }
  }
  swap(&A[i],&A[r]);
  return i;
}

void quickSort(int l,int r,Card *A){
  int q;
  if(l < r){
    q = partition(l,r,A);
    quickSort(l,q-1,A);
    quickSort(q+1,r,A);
  }
}

void merge(int left, int mid, int right,Card *B){
  int n1 = mid - left,n2 = right - mid,i,j,k;
  Card L[n1+1],R[n2+1];
 
  for(i = 0 ; i < n1 ; i++){
    L[i] = B[left + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = B[mid + i];
  }
  L[n1] = R[n2] = (Card){'#',INF};
  for(i = 0,j = 0,k = left ; k < right ; k++){
    if(L[i].num <= R[j].num){
      B[k] = L[i++];
    }else{
      B[k] = R[j++];
    }
  }
}
 
void mergeSort(int left,int right,Card *B){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(left,mid,B);
    mergeSort(mid,right,B);
    merge(left,mid,right,B);
  }
}
