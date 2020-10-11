#include <stdio.h>
#include <math.h>
#define N 500000
#define INFTY 1000000000

void merge(int,int,int);
void mergeSort(int,int);

int A[N];
int n,cnt=0;

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(0,n);
  for(j=0;j<n-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);
  return 0;
}
 void merge(int left,int mid,int right){
   int n1,n2,L[N],R[N],i,j,k;
   n1 = mid-left;
   n2 = right-mid;
   for(i=0;i<n1;i++){
     L[i]=A[left+i];
   }
   for(i=0;i<n2;i++){
     R[i]=A[mid+i];
   }
   L[n1] = INFTY;
   R[n2] = INFTY;
   i = 0;
   j = 0;
    for(k=left;k<right;k++){
     if(L[i]<=R[j]){
       A[k] = L[i];
       i++;
     }
     else {
       A[k] = R[j];
       j++;
     }
     cnt++;
   }
 }
void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
     mid = (left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}

