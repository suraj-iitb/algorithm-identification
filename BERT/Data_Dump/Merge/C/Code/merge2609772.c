#include<stdio.h>
#define MAX 500000
 
int num;
void merge(int s[MAX],int left,int mid, int right){
  int i,j,k,n1,n2,L[250002],R[250002];
  n1 = mid - left;
  n2 = right - mid;
  for (i=0;i<n1;i++) L[i]=s[left+i];
  for (i=0;i<n2;i++) R[i]=s[mid+i];
  L[n1]=10000000000;
  R[n2]=10000000000;
  i=0;
  j=0;
  for (k=left;k < right; k++){
   num++;
    if(L[i]<= R[j]){
      s[k]=L[i];
      i++;
    } else {
      s[k]=R[j];
      j++;
    }
  }
}
 
void mergeSort(int s[MAX],int left, int right) {
  int mid;
  if (left+ 1 < right) {
    mid = (left + right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
}
 
int main() {
  int n,i,s[MAX];
  num=0;
  scanf("%d",&n);
  for(i = 0; i< n;i++)
    scanf("%d",&s[i]);
  mergeSort(s,0,n);
  for(i=0;i<n-1;i++)
    printf("%d ",s[i]);
  printf("%d\n",s[n-1]);
  printf("%d\n",num);
  return 0;
}
