#include <stdio.h>
#define INFTY 1000000001

int mergesort(int *,int,int);
int merge(int *,int,int,int);
int main (){
  int n,i,A[500000],cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  cnt=mergesort(A,0,i);
  for(i=0;i<n;i++){
    if(i)
      printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

int mergesort(int *A,int left,int right){
  int mid,cnt=0;
  if(left+1<right){
    mid=(left+right)/2;
    cnt+=mergesort(A,left,mid);
    cnt+=mergesort(A,mid,right);
    cnt+=merge(A,left,mid,right);
  }
  return cnt;
}
int merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k,cnt=0;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
  return cnt;
}

    
  
  
   
  
    
  

