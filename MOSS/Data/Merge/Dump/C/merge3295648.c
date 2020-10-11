#include<stdio.h>
int A[5000000],cnt;
void merge(int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  int L[n1],R[n2];
  for(i=0; i<n1; i++){
    L[i]=A[left+i];
  }
  for(i=0; i<n2; i++){
    R[i]=A[mid+i];
  }
  L[n1]=2147483647;
  R[n2]=2147483647;
  i=0;
  j=0;
  for(k=left; k<right; k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    cnt++;
  }
}
  
void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}

int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  mergeSort(0,n);

  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

