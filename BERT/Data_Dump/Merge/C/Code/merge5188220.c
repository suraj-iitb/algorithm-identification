#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2+2],R[MAX/2+2];
int c;

void merge(int a[], int n, int left, int mid, int right){
  int i,j,k;

  int N = mid-left;
  int N1=right-mid;
  for(i=0;i<N;i++)L[i]=a[left+i];
  for(i=0;i<N1;i++)R[i]=a[mid+i];
  L[N]=R[N1]=SENTINEL;
  i=j=0;
  for(k=left;k<right;k++){
    c++;
    if(L[i]<=R[j]){
      a[k]=L[i++];
    }else{a[k]=R[j++];}
  }
}

void mergeSort(int a[], int n, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,n,left,mid);
    mergeSort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}

int main(){
  int a[MAX],n,i;
  scanf("%d",&n);
  c=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>=SENTINEL){
      return 1;
    }
  }
  mergeSort(a,n,0,n);

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

