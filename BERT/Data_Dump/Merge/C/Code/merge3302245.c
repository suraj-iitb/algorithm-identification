#include<stdio.h>
#define N 500000
#define S 1000000000
int count;
int L[N/2+2],R[N/2+2];
void merge(int A[],int left ,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<=n2-1;i++){
    R[i]=A[mid+i];
  }
  L[n1]=S;
  R[n2]=S;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    count++;
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
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int A[N],i,n;
  scanf("%d",&n);
  count=0;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>=S) break;
  }
  mergeSort(A,0,n);
  
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
  
    

