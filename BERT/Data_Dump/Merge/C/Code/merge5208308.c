#include<stdio.h>
#include<math.h>
#define MAX 500000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int count=0;

int main(){
  int array[MAX], i, size;

  scanf("%d",&size);

  for(i=0; i<=size-1; i++){
    scanf("%d",&array[i]);
  }
  mergesort(array,0,size);

  for(i=0; i<=size-1; i++){
    printf("%d",array[i]);
    if(i!=size-1) printf(" ");
  }
  printf("\n%d\n",count);


  return 0;
}

void merge(int a[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i, j, k;

  int L[n1], R[n2];

  for(i=0; i<=n1-1; i++) L[i]=a[left+i];
  for(i=0; i<=n2-1; i++) R[i]=a[mid+i];

  L[n1]=(int)INFINITY;
  R[n2]=(int)INFINITY;

  i=0;
  j=0;

  for(k=left; k<=right-1; k++){
    count++;
    if(L[i]<=R[j]){
      a[k]=L[i];
      i=i+1;
    }
    else{
      a[k]=R[j];
      j=j+1;
    }
  }
}

void mergesort(int a[], int left, int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}



