#include <stdio.h>
#define MAX 100000

typedef struct{
  char S;
  int N;
}card;

void merge(card *A,int left,int mid,int right){
  int i,j,k,n1,n2;
  card L[MAX/2+1],R[MAX/2+1];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i] = A[left + i];
  for(i=0;i<n2;i++)
    R[i] = A[mid + i];
  L[n1].N = 2000000000;
  R[n2].N = 2000000000;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].N <= R[j].N){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(card *A,int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int partition(card *A,int p,int r){
  int x,i,j;
  card tmp;
  x = A[r].N;
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].N <= x){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

void quicksort(card *A,int p,int r){
  int q;
  if (p < r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}


int main(){
  int i,j,n,c=1;
  card A[MAX],B[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].S,&A[i].N);
    B[i].S = A[i].S;
    B[i].N = A[i].N;
  }
  quicksort(A,0,n-1);
  mergeSort(B,0,n);

  for(i=0;i<n;i++){
    if(A[i].S != B[i].S)
      c = 0;
  }
  if(c)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].S,A[i].N);
  }
  return 0;
}

