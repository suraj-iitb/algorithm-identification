#include<stdio.h>
#define MAX 500000
#define CENTI 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

void merge(int *, int , int , int, int);
void mergeSort(int *, int , int , int);

int main(){
  int A[MAX], n, i;

  scanf("%d", &n);
  for (i = 0 ; i < n ; i++) scanf("%d", &A[i]);
  
  mergeSort(A, n, 0, n);

for(i = 0; i < n-1; i++) printf("%d ", A[i]);

printf("%d\n", A[i]);
printf("%d\n", cnt);

}

void merge(int A[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

for(i = 0; i < n1; i++) L[i] = A[left + i];

  for(i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1] = R[n2] = CENTI;
  i = 0;
  j = 0;

 for(k = left; k < right; k++) {
   cnt++;

   if(L[i] <= R[j]){
     A[k] = L[i++];
    }
   else A[k] = R[j++];

  }
}

void mergeSort(int A[], int n, int left, int right){
int mid;

if(left+1 < right){
mid = (left + right) / 2;
mergeSort(A, n, left, mid);
mergeSort(A, n, mid, right);
merge(A, n, left, mid, right);
  }

}
