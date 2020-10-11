#include <stdio.h>

#define N 500000
 
int cnt,t[N];
 
void merge    (int A[], int left, int right);
 
main(){
  
  int n,A[N], i;
  scanf("%d", &n);
  
  for(i=0;i<n;i++) scanf("%d", &A[i]);
  merge(A,0, n-1);
  
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n%d\n", A[n-1], cnt);
  
  return 0;
  
}

void merge (int A[], int left, int right){   
  int mid, i, j, k;
  
  if(left >= right) return;
  
  mid = (left + right) / 2;
  
  merge   (A, left, mid);
  
  merge(A, mid+1, right);
  
  for(i=left;i<=mid;i++) t[i] = A[i];
  for(i=mid+1,j=right;i<=right;i++,j--) t[i] = A[j];
  i = left;
  j = right;
  
  for(k=left;k<=right;k++,cnt++){
    if(t[i] <= t[j]) A[k] = t[i++];
    else A[k] = t[j--];
  }
  
}

