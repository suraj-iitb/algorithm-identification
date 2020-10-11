#include<stdio.h>
#define INFTY 2100000001;
void mergeSort(int *A,int left,int right);
void merge(int *A,int left,int mid,int right);

int L[500000],R[500000];
int cnt;

int main(){
  int s[500001],n;
  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);
  //in

  mergeSort(s,0,n);

  for(i=0;i<n-1;i++)
    printf("%d ",s[i]);
  printf("%d\n",s[i]);
  printf("%d\n",cnt);
  
  return 0;
}
void mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    //cnt++;
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
void merge(int *A,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  //cnt++;
  n1 = mid - left;
  n2 = right - mid;
 
  for( i = 0 ;i< n1;i++)
    L[i] = A[left + i];
  for( i = 0;i< n2;i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
    for (k = left;k< right;k++){
      if (L[i] <= R[j]){
	A[k] = L[i];
	i = i + 1;
	cnt++;
      }
      else {
	A[k] = R[j];
	j = j + 1;
	cnt++;
      }
    }
}

