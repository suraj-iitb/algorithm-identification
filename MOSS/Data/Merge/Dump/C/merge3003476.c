#include<stdio.h>
#define N 500000
#define S 1000000000
int L[N],R[N];
int count=0;
void merge(int A[],int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = 2*S;
  R[n2] = 2*S;
  i = 0;
  j = 0;
    for(k=left;k<right;k++){
      count++;
      if(L[i] <= R[j]){
	A[k] = L[i];
	i++;
      }
      else { 
	A[k] = R[j];
      j++;
      }
    }
}

void mergeSort(int A[],int left,int right){
  if (left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  
  int A[N],n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);
    mergeSort(A,0,n);
    
    for(i=0;i<n;i++){
      if(i == n-1)
	printf("%d\n",A[i]);
      else printf("%d ",A[i]);
    }

    printf("%d\n",count);

    return 0;
}

