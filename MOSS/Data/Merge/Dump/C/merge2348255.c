#include <stdio.h>
 
int count = 0;
 
void merge(int *s, int left, int mid, int right){
  
  int i, j, k,n1,n2;
 
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1], R[n2+1];
 
  for(i = 0; i < n1; i++)
    L[i] = s[left + i];
  for(i = 0; i < n2; i++)
    R[i] = s[mid + i];
  L[n1] = 1000000001;
  R[n2] = 1000000001;
 
  i = j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      s[k] = L[i];
      i++;
    } else{
      s[k] = R[j];
      j++;
    }
    count++;
  }
}
 
void mergeSort(int *s, int left, int right){
  
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}
 
int main(){
 
  int i, n, left, mid, right;
 
  scanf("%d", &n);
  int s[n];
  for(i = 0; i < n; i++)
    scanf("%d", &s[i]);
 
  mergeSort(s, 0, n);
   
  for(i = 0; i < n-1; i++){
    printf("%d ", s[i]);}
  
  printf("%d\n", s[i]);
  printf("%d\n", count);
  
  return 0;
}
