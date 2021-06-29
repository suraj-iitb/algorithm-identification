#include<stdio.h>
#include<limits.h>

void merge(int,int,int);
void mergeSort(int,int);

int num[50000000];
int left=0,right;
int L[10000000];
int R[10000000];
int cnt;

int main(){
  int n,i;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  right=n;
  cnt=0;

  mergeSort(left,right);

  for(i=0;i<n;i++){
    if(n==i+1) printf("%d\n",num[i]);
    else printf("%d ",num[i]);
  }
  printf("%d\n",cnt);

  return 0;
}

void mergeSort(int left,int right){
  int mid;
  if (left+1<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,right,mid);
  }
}

void merge(int left,int right,int mid){
  int i,j,k;
  int n1,n2;
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L[i]=num[left+i];
  }
  for(j=0;j<n2;j++){
    R[j]=num[mid+j];
  }
  
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;

  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      num[k]=L[i];
      i++;
    }

    else{
      num[k]=R[j];
      j++;
	}
  }
}
