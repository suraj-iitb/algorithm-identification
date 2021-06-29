#include<stdio.h>
#define N 500000
#define se 1000000000

int Merge(int A[],int left, int mid, int right);
int MergeSort(int A[],int left, int right);

//int A[N];
int c;

int main(){
  int A[N];
  int n;
  int i;
  c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  MergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

int Merge(int A[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;

  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }

  L[n1]=se;
  R[n2]=se;
  
  i=0;
  j=0;
  for(k=left;k<right;k++){
    c++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

int MergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }
}
