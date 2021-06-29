#include <stdio.h>
#define INFTY 1000000000

int R[500000];//right
int L[500000];//left
int cnt=0;


void merge(int A[],int l,int m,int r){
  int n1,n2;
  int i,j;
  int k;

  n1 = m-l;
  n2 = r-m;
  for(i=0;i <= n1-1;i++){
    L[i]= A[l+i];
  }
  for(i=0;i<=n2-1;i++){
    R[i] = A[m+i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i=0;
  j=0;
  for(k=l;k<=r-1;k++){
    if(L[i]<=R[j]){
      A[k] = L[i++];
      cnt++;
    }
    else{
      A[k] = R[j++];
      cnt++;
    }

  }

}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);

  }

}
int main(){
  int A[500000];
  int n;//number
  int i;
  

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);

  }
  
  mergeSort(A,0,n);//left=0,right=n
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;

}



