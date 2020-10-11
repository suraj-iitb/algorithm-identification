#include <stdio.h>
#include <math.h>
//#define INFINITY HUGE_VALF                                                    
//#define HUGE_VALF __builtin_huge_valf()                                       
//#define INFTY 2000000000
#define N 500000
int count,L[N/2+2],R[N/2+2];
//float inf = INFINITY;                                                         
void merge(int * ,int ,int ,int );
void mergeSort(int * ,int ,int );

int main(){
  int n,A[N],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i != n-1)printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] =  2000000000 ;
  //inf;                                                                        
  i = j = 0;
  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
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

