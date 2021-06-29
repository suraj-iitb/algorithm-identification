#include<stdio.h>
#include<math.h>
long long A[500050];
int n,count=0;


void merge(long long A[],int left,int mid,int right){
  int n1=mid-left+1;
  int n2=right-mid;
  long long L[n1],R[n2];
  for(int i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=A[mid+1+i];
  }
  //L[n1]=R[n2]=INFINITY;
  int i=0,j=0,k=left;
  while(i<n1&&j<n2){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }else{
      A[k]=R[j];
      j++;
      count++;
    }k++;
  }
  while(i<n1){
    A[k]=L[i];
    i++;
    k++;
    count++;
  }
  while(j<n2){
    A[k]=R[j];
    j++;
    k++;
    count++;
  }
}

void mergeSort(long long A[],int left,int right){
  if(left<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid+1,right);
    merge(A,left,mid,right);
  }
}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld",&A[i]);
  }
  mergeSort(A,0,n-1);
  for(int i=0;i<n;i++){
    printf("%lld",A[i] );;
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}

