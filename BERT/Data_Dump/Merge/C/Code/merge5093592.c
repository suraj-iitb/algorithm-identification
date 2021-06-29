#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000

int L[(MAX/2)+2],R[(MAX/2)+2];
int cnt;

void merge(int A[],int left,int mid,int right){
  int i;
  int x = mid - left;
  int y = right - mid;

  for(i=0;i<x;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i<y;i++){
    R[i] = A[mid + i];
  }
 
  L[x] = R[y] = INFTY;
    i = 0;
    
    int j = 0;
    int k;
    
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}


void mergesort(int A[],int left,int right){
  if(left+1<right){
    int mid = (left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(){
  int A[MAX],n,i;
   cnt = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergesort(A,0,n);

  for(i=0;i<n;i++){
    if(i != 0) printf(" ");
      printf("%d",A[i]);
          }
    printf("\n");
    printf("%d\n",cnt);

    return 0;
}

