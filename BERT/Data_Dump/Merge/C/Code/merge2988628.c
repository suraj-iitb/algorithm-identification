#include<stdio.h>
#include<stdlib.h>
#define NUM 500000
#define NUM1 1000000000

int count=0;
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int main(){
  int n,i,left,right,a[NUM];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  left=0;
  right=n;
  
  mergeSort(a,left,right);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i+1!=n){
      printf(" ");
    }
  }
  printf("\n%d\n",count);

  return 0;
}

void merge(int *a,int left,int mid,int right){
  int i,j,k,n1,n2;
  int *L;
  int *R;
  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=NUM1;
  R[n2]=NUM1;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
      count++;
    }else{
      a[k]=R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
}

void mergeSort(int *a,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

