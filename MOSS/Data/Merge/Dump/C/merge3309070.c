#include <stdio.h>
#define F 1000000000
#define M 500000
int total=0,A[M];
int L[M/2+2],R[M/2+2];
void merge(int,int,int);
void mergeSort(int,int);
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
}
  mergeSort(0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
}
  printf("%d\n",A[n-1]);
  printf("%d\n",total);

  return 0;
}
void merge(int left,int mid,int right){
  int i,j,k,n1,n2;
n1=mid-left;
n2=right-mid;
 for(i=0;i<n1;i++){
   L[i]=A[left+i];
      }
 for(i=0;i<n2;i++){
   R[i]=A[mid+i];
      }
 L[n1]=F;
 R[n2]=F;
    i=0;
    j=0;
    for(k=left;k<right;k++){
      total++;
      if(L[i]<=R[j]){
	A[k]=L[i];
	i=i+1;
      }
      else{ 
	A[k]=R[j];
	j=j+1;
	}
    }
}
void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
  mid=(left+right)/2;
  mergeSort(left,mid);
  mergeSort(mid,right);
  merge(left,mid,right);
    }
      }

