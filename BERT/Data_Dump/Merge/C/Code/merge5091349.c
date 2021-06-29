#include<stdio.h>

#define INFTY 1000000000
#define N 500000

void merge(int *,int,int,int);
void mergeSort(int *, int,int);

int count=0;

int main(){
  int i,j,n;
  int S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i=0;i<n-1;i++)printf("%d ",S[i]);
  printf("%d\n",S[i]);
  printf("%d\n",count);

  return 0;
}
void mergeSort(int A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

  void merge(int A[],int left,int mid,int right){
 int n1 = mid - left;
 int n2 = right - mid;
  /* L[0...n1], R[0...n2] を生成*/
 int L[n1],R[n2];
 int i,j,k;

 for( i = 0 ;i <= n1-1;i++) L[i] = A[left + i];
 for( i = 0 ;i <= n2-1;i++) R[i] = A[mid + i];
 L[n1] = INFTY;
 R[n2] = INFTY;
 i = 0;
 j = 0;
 for(k = left; k<= right-1; k++){
   count++;
   if(L[i] <= R[j]){
     A[k] = L[i];
       i = i + 1;
   }
   else{
     A[k] = R[j];
     j = j + 1;
       }
    }
  }


