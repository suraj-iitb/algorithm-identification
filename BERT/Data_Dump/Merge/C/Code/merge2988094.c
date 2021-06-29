#include <stdio.h>
#include <limits.h>
#define N 500000
void Merge(int,int,int);
void MergeSort(int,int);
int s[N],count=0;
int main(){
  int n,i;
  scanf("%d",&n);
  for(i = 0 ; i<n ;i++){
    scanf("%d",&s[i]);
  }
  MergeSort(0,n);
  for(i = 0 ; i<n ;i++){
    if(i == n-1)  printf("%d\n%d\n",s[i],count);
    else printf("%d ",s[i]);
  }
  return 0;
}

void Merge(int left ,int mid ,int right){
  int n1,n2,i,j,k;
  n1 = mid -left;
  int L[n1];
  n2 = right - mid;
  int R[n2];

  for( i =0 ;i<=n1-1;i++){
    L[i]=s[left +i];
  }
  for( i =0 ;i<=n2-1;i++){
    R[i]=s[mid +i];
  }
  L[n1] =INT_MAX;
  R[n2] = INT_MAX;
  i=0;
  j=0;
  for(k= left ;k<=right-1;k++){
    if(L[i] <= R[j]){
      count++;
      s[k] = L[i];
      i=i+1;
    }
    else {
      count++;
      s[k] = R[j];
      j=j+1;
    }
  }
}
void MergeSort(int left ,int right){
  int mid;
  if(left +1 <right){
    mid =(left +right)/2;
    MergeSort(left,mid);
    MergeSort(mid,right);
    Merge(left,mid,right);
  }
}

