#include <stdio.h>
#include <math.h>

void merge(int,int,int);
void mergeSort(int,int);

long int A[1000000];
int count=0;

int main(){
  int a,i,j;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(0,a);
  for(j=0;j<a-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[a-1]);
  printf("%d\n",count);
  return 0;
}
 void merge(int left,int mid,int right){
   long int n1,n2,L[1000000],R[1000000],i,j,k;
   n1 = mid-left;
   n2 = right-mid;
   for(i=0;i<n1;i++){
     L[i]=A[left+i];
   }
   for(i=0;i<n2;i++){
     R[i]=A[mid+i];
   }
   L[n1] = 10000000000;//INFINITY;
     R[n2] = 10000000000;//INFINITY;
   i = 0;
   j = 0;
   for(k = left;k<right;k++){
     if(L[i]<=R[j]){
       A[k] = L[i];
       i=i+1;
     }
     else {
       A[k] = R[j];
       j = j+1;
     }
     count++;
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
	

