#include<stdio.h>
  
int L[500000], R[500000], count;
  
void merge(int S[], int n, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i = 0;i < n1;i++) L[i] = S[left+i];
  for(i = 0;i < n2;i++) R[i] = S[mid+i];
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  i = 0; j = 0;
  for(k = left;k < right;k++){
    count++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    } else{
      S[k] = R[j];
      j++;
    }
  }
}
 
void mergeSort(int S[], int n, int left, int right){
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergeSort(S, n, left, mid);
    mergeSort(S, n, mid, right);
    merge(S, n, left, mid, right);
  }
}
 
int main()
{
  int S[500000], n, i;
  count = 0;
   
  scanf("%d", &n);
  
  for(i = 0;i < n;i++) scanf("%d", &S[i]);
  
  mergeSort(S, n, 0, n);
 
  for(i = 0;i < n;i++){
    if(i) printf(" ");
    printf("%d", S[i]);
  }
 
  printf("\n");
 
  printf("%d\n", count);
   
  return 0;
}
