#include<stdio.h>
#define MAX 100000
#define N 200000000
struct card{
  char s;
  int nn;
};

struct card L[MAX], R[MAX];

void merge(struct card A[], int n, int left, int mid ,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0 ; i<n1; i++){
    L[i] = A[left +i];
  }

  for(i = 0; i < n2; i++){
    R[i] = A[mid +i];
  }

  L[n1].nn = N;

  R[n2].nn = N;

  i = 0;
  j = 0;

  for(k = left ; k<right ; k++){
    if(L[i].nn <= R[j].nn){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void m_sort(struct card A[], int n, int left,int right){
  int m;
  if(left+1 < right){
    m = (left +right)/2;
    m_sort(A,n,left,m);
    m_sort(A,n,m,right);
    merge(A,n,left,m,right);
  }
}

int partition(struct card A[] ,int n, int p, int r){
  int i,j;
  struct card t,x;
  x = A[r];
  i = p - 1;
  for(j = p; j<r ; j++){
    if(A[j].nn <= x.nn){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }
  t = A[i +1];
  A[i+1] = A[r];
  A[r] = t;
  return i + 1;
}

void quickSort(struct card A[], int n, int p,int r){
  int q;
  if(p < r){
    q = partition(A,n,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}

int main(){
  int i,n,v;
  struct card A[MAX],B[MAX];
  char M[10];
  int stable = 1;

  scanf("%d",&n);
  for(i = 0; i<n; i++){
    scanf("%s %d",M,&v);
    A[i].s = M[0];
    B[i].s = M[0];
    A[i].nn = v;
    B[i].nn = v;
  }
  m_sort(A,n,0,n);
  quickSort(B,n,0,n-1);

  for(i = 0; i<n; i++){
    if(A[i].s != B[i].s){
      stable = 0;
    }
  }

  if(stable == 1){
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }
  for(i = 0 ;i < n ;i ++){
    printf("%c %d\n",B[i].s,B[i].nn);
  }
  return 0;
}

