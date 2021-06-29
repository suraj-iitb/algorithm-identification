#include<stdio.h>
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int c=0;
int main(){
  int i,n,s[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  mergeSort(s,0,n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",s[i]);
  }
  printf("\n%d\n",c);
  return 0;
}
void merge(int s[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2],i,j,k;
  for(i=0;i<n1;i++)L[i] = s[left + i];
  for(i=0;i<n2;i++)R[i] = s[mid + i];
  L[n1] = 999999999;
  R[n2] = 999999999;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if( L[i] <= R[j]){
      s[k] = L[i];
      i = i + 1;
    }
    else {
      s[k] = R[j];
      j = j + 1;
    }
    c++;
  }
}
void mergeSort(int s[],int left,int right){
  int mid;
  if( left+1 < right){
    mid = (left + right)/2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}
