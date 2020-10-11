#include<stdio.h>
int r[250001],l[250001];
int cnt=0;
void merge(int A[],int left,int mid,int right);
void mergeSort(int A[],int left,int right);
int main(){
  int n,i,left,mid,right;
  int A[500010];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
  printf("%d",A[i]);
  if(i!=n-1)printf(" ");
  else printf("\n");
  }
  printf("%d\n",cnt);
  return 0;
}
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    l[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=A[mid+i];
  }
  l[n1]=1000000000;
  r[n2]=1000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(l[i]<=r[j]){
      A[k]=l[i];
      i=i+1;
    }
    else{
      A[k]=r[j];
      j=j+1;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

  

