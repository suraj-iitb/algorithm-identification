#include <stdio.h>
#define INF 1000000000
#define N 500000
void merge(int , int , int);
void mergeSort(int ,int);

int A[N];
int L[N/2+1],R[N/2+1];
int count=0;
int main(){
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(0, n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;

}

void merge(int left, int mid, int right){
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];
  L[n1]=INF+100;
  R[n2]=INF+100;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
    count++;
  }
}
  
void mergeSort(int left,int right){
  int mid;
  if(left+1 < right){
    mid=(left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
