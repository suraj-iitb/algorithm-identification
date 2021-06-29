
#include <stdio.h>
void mergesort(int*,int,int); 
void merge(int*,int,int,int); 
int c=0;
int main(){
  int n,a[500000],i,mid;
  scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&a[i]);
   mid=n/2;
   mergesort(a,0,n);
  for(i=0;i<n-1;i++)  
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],c);
  return 0;
}
void mergesort(int A[], int left,int right){
  int mid;
  if (left+1 < right){
    
mid = (left + right)/2;
    mergesort(A, left, mid);
      mergesort(A, mid, right);
      merge(A, left, mid, right);
}
}
  void merge(int A[],int left,int mid,int right){
  int i,j,k,n1,n2,L[500000],R[500000];  

  n1 = mid - left;
  n2 = right - mid;

  for (i = 0; i<n1;i++)
    L[i] = A[left + i];
  for (i = 0; i<n2;i++)
    R[i] = A[mid + i];
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;
  for (k = left;k< right;k++)
{
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      c++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      c++;    
}
  }
  }
