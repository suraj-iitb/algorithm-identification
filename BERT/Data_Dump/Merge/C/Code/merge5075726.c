#include <stdio.h>
#define N 500000
#define S 2000000000
int l[N/2+2],r[N/2+2];
int cnt;
void merge(int [],int,int,int,int);
void mergesort(int [],int,int,int);
int main(){
  int a[N],n,i;
  cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  mergesort(a,n,0,n);
  for(i=0;i<n;i++){
    if(i>=1){
      printf(" ");
    }
    printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

void merge(int a[],int n,int left,int mid,int right){
  int n1,n2,i,j,k=0;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    l[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }
  l[n1]=r[n2]=S;
  i=0;
  for(j=left;j<right;j++){
    cnt++;
    if(l[i]<=r[k]){
      a[j]=l[i++];
    }else{
      a[j]=r[k++];
    }
  }
}

void mergesort(int a[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(a,n,left,mid);
    mergesort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}


