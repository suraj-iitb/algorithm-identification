#include <stdlib.h>
#include <stdio.h>
void merge(int *,int,int,int);
void mergesort(int *,int,int);
int cnt=0,n;
int main(){
  int a[500000],i;
  scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
  mergesort(a,0,n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",cnt);
  return 0;
}
void mergesort(int *a,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}
void merge(int *a,int left,int mid,int right){
  int l,i,k,j,n1=mid-left,n2=right-mid;
  int *L,*R;
  L=malloc(sizeof(int)*(n1+2));
  R=malloc(sizeof(int)*(n2+2));
  for(i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=2147483647;
  R[n2]=2147483647;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j])a[k]=L[i++];
    else a[k]=R[j++];
  }
  free(L);
  free(R);
}

