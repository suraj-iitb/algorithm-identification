#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define INF INT_MAX

int A[MAX+1], B[MAX+1], L[MAX/2+1], R[MAX/2+1];
char C_A[MAX+1], C_B[MAX+1], C_L[MAX/2+1], C_R[MAX/2+1];
int n;

int partition(int l, int r){
  int x;
  int i, j;

  x=A[r];

  for(i=l, j=l; i<r; i++){
    if(A[i]<=x){
      swap(A[i], A[j]);
      swap(C_A[i], C_A[j]);
      j++;
    }
  }
  swap(A[j], A[r]);
  swap(C_A[j], C_A[r]);
  
  return j;
}

void quickSort(int l, int r){
  int p;

  if(l < r){
    p=partition(l, r);
    quickSort(l, p-1);
    quickSort(p+1, r);
  }
}

void merge(int n, int left, int mid, int right){
  int n1=mid-left;
  int n2=right-mid;

  for(int i=0; i<n1; i++){
    L[i]=B[left+i];
    C_L[i]=C_B[left+i];
  }
  for(int i=0; i<n2; i++){
    R[i]=B[mid+i];
    C_R[i]=C_B[mid+i];
  }
  
  L[n1]=INF;
  R[n2]=INF;

  for(int i=0, j=0, k=left; k<right; k++){
    if(L[i]<=R[j]){
      B[k]=L[i];
      C_B[k]=C_L[i];
      i++;
    }else{
      B[k]=R[j];
      C_B[k]=C_R[j];
      j++;
    }
  }
}

void merge_sort(int n, int left, int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    merge_sort(n, left, mid);
    merge_sort(n, mid, right);
    merge(n, left, mid, right);
  }
}

int main(void){
  int i;
  
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf(" %c %d", &C_A[i], &A[i]);
    B[i]=A[i]; C_B[i]=C_A[i];
  }
  
  quickSort(0, n-1);
  merge_sort(n, 0, n);

  for(i=0; i<n; i++){
    if(C_A[i] != C_B[i]){
      printf("Not stable\n");
      break;
    }
  }
  if(i == n) printf("Stable\n");
      
  for(i=0; i<n; i++) printf("%c %d\n", C_A[i], A[i]);
  
  return 0;
}

