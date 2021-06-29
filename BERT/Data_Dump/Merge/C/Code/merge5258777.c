#include<stdio.h>
#define INFTY 2000000000
int count=0;

void merge(int a[],int left,int mid,int right){
  int n1,n2,i;

  n1=mid-left;
  n2=right-mid;

  int l[n1+1],r[n2+1];

  for(i=0;i<n1;i++){
    l[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }
  l[n1]=INFTY;
  r[n2]=INFTY;

  int j=0,k;
  i=0;

  //ここで結合
  for(k=left;k<right;k++){
    count++;
    if(l[i]<=r[j]){
      a[k]=l[i];
      i++;
    }else{
      a[k]=r[j];
      j++;
    }
  }
}

void mergesort(int a[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}

int main(void){
  int n,i,a[500005];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  mergesort(a,0,n);

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1){printf(" ");}
  }
  printf("\n%d\n",count);
  return 0;
}
