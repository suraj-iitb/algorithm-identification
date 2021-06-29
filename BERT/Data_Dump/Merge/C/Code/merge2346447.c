#include<stdio.h>
#define N 500000
#define MAX 1000000000

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int n,count=0;


int main(){
  int i,S[N],l,r;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  l=0;
  r=n-1;

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i>=1)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}
void mergeSort(int *s, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
}
void merge(int *s, int left, int mid, int right){
  int i,j,k,n1,n2;
  
  n1=mid-left;
  n2=right-mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++){
    L[i]=s[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=s[mid+i];
  }

  L[n1]=MAX;
  R[n2]=MAX;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      s[k]=L[i];
      i=i+1;
    }
    else{
      s[k]=R[j];
      j=j+1;
    }
  }
  count+=(i+j);
}
