#include<bits/stdc++.h>
using namespace std;

#define MAX 500000
#define INF INT_MAX

int A[MAX+1], L[MAX/2+1], R[MAX/2+1];
int cnt;

void merge(int n, int left, int mid, int right){
  int n1=mid-left;
  int n2=right-mid;

  for(int i=0; i<n1; i++) L[i]=A[left+i];
  for(int i=0; i<n2; i++) R[i]=A[mid+i];

  L[n1]=INF;
  R[n2]=INF;

  for(int i=0, j=0, k=left; k<right; k++){
    cnt++;
    
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
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
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%d", &A[i]);
  merge_sort(n, 0, n);

  for(int i=0; i<n; i++){
    if(i) printf(" %d", A[i]);
    else printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);
  
  return 0;
}

