#include<stdio.h>
#define N 500001
void Merge(int A[],int left,int mid,int fuck);
void MergeSort(int A[], int left, int right);
int count = 0;

int main(){
  int A[N];
  int i,n;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

 
      MergeSort(A, 0, n);
      for(i = 0; i < n; i++){
	if(i == n-1)	printf("%d\n",A[i]);
	else printf("%d ",A[i]);
      }
      printf("%d\n",count);
      return 0;
}

void Merge(int A[],int left,int mid,int right){
   
  int i, j = 0, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  
  for (i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1]=1000000000;
  R[n2]=1000000000;
  i = 0;
  
  for(k = left; k < right; k++){
    count++;
    if (L[i] <= R[j]){
      A[k] = L[i];
	i = i + 1;
	
    } else {
      A[k] = R[j];
      j = j + 1;
      }
  }
  
}

void MergeSort(int A[], int left, int right){
  int mid = 0;
  if(left + 1 < right){
    mid = (left + right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
  
}
