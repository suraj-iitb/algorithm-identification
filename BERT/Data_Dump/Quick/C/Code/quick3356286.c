#include <stdio.h>
#include <limits.h>
#define N 1000000

typedef struct data{
  char c;
  int  v;
}DATA;


DATA L[N],R[N];
int n;
void mergeSort(DATA *, int, int );
void merge(DATA *, int , int , int );
int partition(DATA *, int, int );
void quickSort(DATA *, int ,int );

int main(){

  int i,v;
  DATA Card_A[N],Card_B[N];
  char S[5];
  int stable =1;

  scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%s %d", S, &v);
    Card_A[i].c = Card_B[i].c = S[0];
    Card_A[i].v = Card_B[i].v = v;
  }

  mergeSort(Card_A, 0, n);
  quickSort(Card_B, 0, n-1);

  for(i=0;i<n;i++){
    if(Card_A[i].c != Card_B[i].c)stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  
 for(i=0;i<n;i++){
   printf("%c %d\n" ,Card_B[i].c, Card_B[i].v);
  }

  
  
  return 0;
}

void mergeSort( DATA Card_A[], int left, int right){

  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(Card_A,left,mid);
    mergeSort(Card_A,mid,right);
    merge(Card_A, left, mid, right);
  }
  
}

void merge(DATA Card_A[], int left, int mid, int right){
  int n1,n2;
  int i,j,k;

  n1 = mid -left;
  n2 = right -mid;

  for(i=0;i<n1;i++){
    L[i] = Card_A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = Card_A[mid+i];
  }

  L[n1].v = INT_MAX;
  R[n2].v = INT_MAX;

  i=j=0;

  for(k=left; k<right ; k++){
    if(L[i].v <= R[j].v){
      Card_A[k] = L[i];
      i++;
    }else{
      Card_A[k] = R[j];
      j++;
    }
  }  
}

void quickSort(DATA Card_A[], int p, int r){
  int q;
  if(  p < r ){
    q = partition(Card_A,p,r);
    quickSort(Card_A,p,q-1);
    quickSort(Card_A,q+1,r);
  }
}

int partition(DATA Card_A[] , int p ,int r ){
  int i,j;

  DATA t,x;
  x = Card_A[r];
  i = p-1;
  for(j=p; j < r ; j++){
    if(Card_A[j].v <= x.v){
      i++;
      t = Card_A[i];
      Card_A[i] = Card_A[j];
      Card_A[j] = t;

    }
  }
  t = Card_A[i+1];
  Card_A[i+1] = Card_A[r];
  Card_A[r] = t;
  return i+1;
  
}

