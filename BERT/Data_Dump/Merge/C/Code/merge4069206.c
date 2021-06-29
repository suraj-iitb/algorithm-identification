#include<stdio.h>

void merge(int A[],int left,int mid,int right,int *cnt){
  int i,j,k,n1,n2;
  int L[500001],R[500001];

  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];

  L[n1]=1000000001;
  R[n2]=1000000001;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){(*cnt)++;
      A[k]=L[i];
      i++;
    }
    else{(*cnt)++;
      A[k]=R[j];
      j++;
    }
  }


}

void mergeSort(int A[],int left,int right,int *cnt){
  int mid;
  if(left+1 < right){
    mid=(left+right)/2;
    mergeSort(A,left,mid,cnt);
    mergeSort(A,mid,right,cnt);
    merge(A,left,mid,right,cnt);
  }


}



int main(){
  int n,i;
  int A[500001];
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  mergeSort(A,0,n,&cnt);

  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[n-1]);

  printf("%d\n",cnt);

  return 0;
}

