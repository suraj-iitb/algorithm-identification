#include<stdio.h>
#include<stdlib.h>
#define N 500001
#define S 1000000001

int c = 0;

void Merge(int A[],int left,int mid,int right){

  int n1 = mid-left,n2 = right - mid;
  int i,j,k;
  int L[n1+1],R[n2+1];

  for(i=0;i<=n1-1;i++)
    L[i]=A[left+i];

  for(i=0;i<=n2-1;i++)
    R[i]=A[mid+i];

  L[n1]=S;
  R[n2]=S;
  i = j = 0;

  for(k=left; k<=right-1; k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i = i + 1;
      c++;
    }
    else {
      A[k]=R[j];
      j = j + 1;
      c++;
    }
  }
}
 
void Merge_Sort(int A[], int left, int right){
  int mid;

  if(left+1<right){
    mid = (left + right)/2;
    Merge_Sort(A, left, mid);
    Merge_Sort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main(){
  int n,i,A[N];
 
  scanf("%d", &n);

  for(i=0; i<n; i++)
    scanf("%d", &A[i]);
 
  Merge_Sort(A, 0, n);
 
  for(i=0; i<n-1; i++)
    printf("%d ",A[i]);

  printf("%d\n",A[n-1]);
  printf("%d\n",c);
 
  return 0;
   
}
