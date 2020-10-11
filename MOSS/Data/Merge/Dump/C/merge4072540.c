#include<stdio.h>
int A[5000004];
int L[2500004];
int R[2500004];
int INFTY = 999999999;
int k;
int cnt;
void merge(int left, int mid, int right){
  int i,j;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0;i <= n1-1;i++){
    L[i] = A[left + i];
  }
  for (i = 0;i <= n2-1;i++){
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  }
  i = 0;
  j = 0;

  for (k = left;k <= right-1;k++){
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i++];
    }
    else 
      A[k] = R[j++];
  }
}

void mergeSort(int left, int right){
  if (left+1 < right){
    int mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  int i,a,b,n;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  
    mergeSort(0,a);

    for(i = 0;i < a-1;i++){
    printf("%d",A[i]);
    if(i < a-1){
      printf(" ");
    }
  }
  printf("%d\n",A[a-1]);
  printf("%d\n",cnt);
return 0;
}
