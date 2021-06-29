#include<stdio.h>
#include<limits.h>

#define N 500000

int s[N],count=0;

void Merge(int left, int mid, int right){
  int n_l,n_r;
  int i,j,k;

  n_l=mid-left;
  int L[n_l];
  
  n_r=right-mid;
  int R[n_r];

  for(i=0;i<=n_l-1;i++){
    L[i]=s[left+i];
  }

  for(i=0;i<=n_r-1;i++){
    R[i]=s[mid+i];
  }

  L[n_l]=INT_MAX;
  R[n_r]=INT_MAX;
  i=0;
  j=0;

  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      count++;
      s[k]=L[i];
      i=i+1;
    }
    else {
      count++;
      s[k]=R[j];
      j=j+1;
    }
  }

}

void MergeSort(int left, int right){
  int mid;

  if(left+1 < right){
    mid=(left+right)/2;
    MergeSort(left,mid);
    MergeSort(mid,right);
    Merge(left,mid,right);
  }
}



int main(){
  int n,i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);

  MergeSort(0,n);

  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",s[i]);
      printf("%d\n",count);
    }
    else    printf("%d ",s[i]);
  }

  return 0;
}

