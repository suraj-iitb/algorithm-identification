#include<stdio.h>
#include<limits.h>
#define N 500000
void Merge(int[],int,int,int);
void MergeSort(int[],int,int);
int s;
int main(){
  int n,i,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  MergeSort(A,0,n);
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",s);
  return 0;
}

void Merge(int A[],int left,int mid,int right){
  int nn,nnn,i,j,k;
  nn=mid-left;
  nnn=right-mid;
  int L[nn+1],R[nnn+1];
  for(i=0;i<nn;i++)
    L[i]=A[left+i];
  for(i=0;i<nnn;i++)
    R[i]=A[mid+i];
    L[nn]=INT_MAX;   
    R[nnn]=INT_MAX;   
    i=0;
    j=0;
    for(k=left;k<right;k++){
      s++;
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


void MergeSort(int A[],int left,int right){
  int mid;  
  if(left+1<right) {
    mid=(left+right)/2;
    MergeSort(A,left,mid);    
    MergeSort(A,mid,right);    
    Merge(A,left,mid,right);    
  }
}
