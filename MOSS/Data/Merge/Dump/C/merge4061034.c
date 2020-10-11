#include <stdio.h>
#define N 500000
#define MAX 1000000000

int cnt = 0;

void merge(int *a,int left,int mid,int right){
  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  int L[n1+1], R[n2+1];

  for(i=0;i<n1;++i)L[i]=a[left+i];
  L[n1]=MAX;

  for(i=0;i<n2;++i)R[i]=a[mid+i];
  R[n2]=MAX;

  i = j = 0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else {
      a[k]=R[j];
      j++;
    }
    cnt++;
  }
 
}

void mergeSort(int *a,int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);

  }
}


int main(){
  int a[N],n,i;

  scanf("%d",&n);
  for(i=0;i<n;++i)scanf("%d",&a[i]);

  mergeSort(a,0,n);

  for(i=0;i<n-1;++i)printf("%d ",a[i]);

  printf("%d\n%d\n",a[n-1],cnt);

  return 0;

  
}

