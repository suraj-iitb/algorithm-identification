#include<stdio.h>
#define NUM 500000
#define INFTY 1000000000

void mergeSort(int*,int, int);
void merge(int*,int,int,int);

int a[NUM];
int count=0;

int main(){
  int n,i,mid,left,right;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  left=0;
  right=n;
  

  mergeSort(&a[0],left,right);

  for(i=0;i<n;i++){
   
    printf("%d",a[i]);
    if(i+1!=n){
      printf(" ");
    }
  }
  
  printf("\n");
  printf("%d\n",count);
  
  
  return 0;
}


void merge(int *a,int left,int mid,int right){
  int n1,n2,L[NUM],R[NUM],i,j,k;
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i=i+1;
      count++;
    }
    else{
      a[k]=R[j];
      j=j+1;
      count++;
    }
  }
  
  
  
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

