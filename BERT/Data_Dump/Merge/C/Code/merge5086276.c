#include <stdio.h>
#define MAX 500000
#define INFTY 1000000001
int A[MAX],B[MAX],C[MAX];
int cnt=0;


void merge(int left,int mid,int right){
  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<=n1-1;i++){
    B[i]=A[left+i];
  }
  for(i=0;i<=n2-1;i++){
    C[i]=A[mid+i];
  }
  B[n1]=INFTY;
  C[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    cnt++;
    if(B[i]<=C[j]){
      A[k]=B[i++];
    }
    else {
      A[k]=C[j++];
    }
  }
}
  
void mergeSort(int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

  

int main(){
 
  int i,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(0,n);

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}


