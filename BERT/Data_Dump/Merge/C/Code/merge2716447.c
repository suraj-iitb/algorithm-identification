#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int n;
int count=0;

void merge(int *A,int left,int mid,int right){
  int *L,*R;
  L=malloc(sizeof(int)*(mid-left+1));
  R=malloc(sizeof(int)*(right-mid+1));
  
  int i;
  for(i=0;i<mid-left;i++) L[i]=A[left+i];
  L[mid-left]=1000000001;
  for(i=0;i<right-mid;i++) R[i]=A[mid+i];
  R[right-mid]=1000000001;
  
  int l,r;
  l=0;
  r=0;
  for(i=0;i<right-left;i++){
    count+=1;
    if(L[l] <= R[r]){
      A[left+i]=L[l];
      l+=1;
     }
    else{
      A[left+i]=R[r];
      r+=1;
    }
  }
  free(L);
  free(R);
}




void mergesort(int *A,int left,int right){
  if(left +1 < right){
    int mid;
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}



int main(){
  int *A;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergesort(A,0,n);
  
  printf("%d",A[0]);
  for(i=1;i<n;i++) printf(" %d",A[i]);
  printf("\n%d\n",count);
  return 0;
}
  


