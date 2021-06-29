#include <stdio.h>
void merge(int *,int,int,int);
void mergesort(int *,int,int);
#define N 500000
#define banpei 2000000000
int count =0;

int main(){
  int A[N];
  int i,n,left,right,mid,j;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergesort(A,0,n);
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d",A[n-1]);
  
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

void merge(int A[],int left,int mid,int right){
  int i,j,n1,n2,k;
  
  n1 = mid - left;
  n2 = right - mid;
  int L[n1], R[n2];
  
 for(i =0;i<=n1-1;i++)L[i] = A[left + i];

 for(i=0;i<=n2-1;i++)R[i] = A[mid + i];

 L[n1] = banpei;
 R[n2] = banpei;
 i = 0;
 j = 0;

 for(k=left;k<=right-1;k++){count++;
    if(L[i]<=R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }

}

void mergesort(int A[],int left,int right){

  if(left+1<right){
 int   mid = (left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

