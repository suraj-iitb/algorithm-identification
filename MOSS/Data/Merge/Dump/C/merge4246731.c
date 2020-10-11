#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 500000

void Merge(int [],int,int,int,int *);
void MergeSort(int [],int,int,int *);

int main(){
int A[MAX],n;
int cnt = 0;
int i;

scanf("%d",&n);
for (i = 0;i < n;i++)
scanf("%d",&A[i]);

MergeSort(A,0,n,&cnt);

for (i = 0;i < n;i++){
if (i)
printf(" ");

printf("%d",A[i]);
}

printf("\n%d\n",cnt);

  return 0;
}

void Merge(int A[],int left,int mid,int right,int *cnt){
  int n1,n2;
  int i,j,k;
  int *L,*R;

  n1 = mid - left;
  n2 = right - mid;
  L = (int *)malloc(sizeof(int) * (n1 + 1));
  R = (int *)malloc(sizeof(int) * (n2 + 1));
  
  for (i = 0;i < n1;i++)
    L[i] = A[left + i];

  for (i = 0;i < n2;i++)
    R[i] = A[mid + i];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;

  for (k = left;k < right;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }

    else{ 
      A[k] = R[j];
      j = j + 1;
    }

    (*cnt)++;
  }

}

void MergeSort(int A[],int left,int right,int *cnt){
 int mid;

  if (left+1 < right){
    mid = (left + right)/2;
    MergeSort(A, left, mid,cnt);
    MergeSort(A, mid, right,cnt);
    Merge(A, left, mid, right,cnt);
    }

    }
