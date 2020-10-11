#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000

int num=0;
void merge(int *s,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  
int L[n1],R[n2];
for(i = 0;i < n1;i++){
  L[i] = s[left + i];
 }
for(i = 0;i < n2; i++){
  R[i] = s[mid + i];
 }
 L[n1] = INFTY;
 R[n2] = INFTY;
 i = 0;
 j = 0;
 for(k = left;k< right; k++){
   num++;
    if(L[i] <= R[j]){
      s[k] = L[i];
      i = i + 1;
    }
    else {
      s[k] = R[j];
      j = j + 1;
    }
  }
}
void mergeSort(int *s,int left,int right){
  int mid;
  if(left+1 < right){
       mid = (left + right)/2;
       mergeSort(s, left, mid);
       mergeSort(s, mid, right);
       merge(s, left, mid, right);
  }
}


//int left,right,mid,num=0;

int main(){
  int i,n,A[1000000];
  scanf("%d", &n);
  for(i = 0;i < n; i++){
    scanf("%d", &A[i]);
  }
  mergeSort(A,0,n);
  for(i = 0;i<n;i++){
    printf("%d", A[i]);
    if(i < n-1)printf(" ");
  }
  printf("\n%d\n", num);
  return 0;
}
