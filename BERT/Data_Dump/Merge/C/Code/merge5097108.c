#include<stdio.h>
#include <limits.h>
#include<math.h>
#define MAX 500001
int count = 0;
void merge(int A[],int left,int mid,int right){
  int i,j,n1,n2,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++){
    L[i] = A[left+i];
}
   for(i=0;i<n2;i++){
    R[i] = A[mid+i];
}
   L[n1]=R[n2] = INT_MAX;
   i=j=0;
   for(k=left;k<right;k++){
     count++;
     if(L[i] <= R[j]){
       A[k] = L[i];
       i = i +1;
     }
     else{
       A[k] = R[j];
       j = j + 1;
     }
   }
  
}
void Sort(int A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left+right)/2;
    Sort(A,left,mid);
    Sort(A,mid,right);
    merge(A,left,mid,right);
}
}
int main(){
  int i,n,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  Sort(A,0,n);
   for(i=0;i<n;i++){
     if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
   printf("\n%d\n",count);
  return 0;
}

