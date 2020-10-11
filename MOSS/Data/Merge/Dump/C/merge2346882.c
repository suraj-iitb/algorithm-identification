#include<stdio.h>

#define MAX 5000000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];
int A[MAX];
//int mid;
int cnt;

void merge(int A[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else {
      A[k]=R[j];
      j++;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  //printf("%d %d\n",left,right);
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int n,i;
  cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 

  //for(i=0;i<n;i++) printf("%d ",A[i]); 
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",cnt);
  return 0;
}
