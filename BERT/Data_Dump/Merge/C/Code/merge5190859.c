#include<stdio.h>
#include<math.h>

#define MAX 500000
#define SMAX 1000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt=0;

void merge(int A[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
   for(i=0; i<n1; i++){
    L[i] = A[left + i];
   }
    for(i=0; i<n2; i++){
    R[i] = A[mid + i];
    }
    L[n1] = SMAX;
    R[n2] = SMAX;
    i=0;
    j=0;
    for(k=left; k < right; k++){
        cnt++;
        if(L[i] <= R[j])
        {
         A[k] = L[i];
        i++;
          }
        else
        {
        A[k] = R[j];
        j++;
          }
    }
}
    
void mergeSort(int A[], int left, int right){
    int mid;
    if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
    }
}

int main() {
    int i,n,A[MAX];
    scanf("%d", &n);
    for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    }
    
    mergeSort(A, 0, n);
    
    for(i=0;i<n-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
	printf("%d\n",cnt);
    
    return 0;
}
