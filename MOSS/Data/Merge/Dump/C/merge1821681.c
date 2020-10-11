#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Merge(int *,int,int,int);
void MergeSort(int *,int,int);

int count=0;

int main(){
  int n,*A,i,left=0,right;

  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  right=n;
  MergeSort(A,left,right);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }printf("\n%d\n",count);


  free(A);
  return 0;
}
void Merge(int *A,int left,int mid,int right){

  int n1,n2,i,j,k,*L,*R;

  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));
  for(i=0;i<n1;i++) L[i]=A[left +i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }

  free(L);
  free(R);
}
void MergeSort(int *A,int left,int right){

  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }

}
