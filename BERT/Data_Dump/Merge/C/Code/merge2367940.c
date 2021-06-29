#include<stdio.h>
#define INFTY 1000000000

int l[500000]={};
int r[500000]={};
int a;
int hairetu[1000000];
void merge(int,int,int);
void mergesort(int,int);

int main(){
  int b,i,left,right;
  a=0;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&hairetu[i]);
  }
  left=0;
  right=b;
  mergesort(left,right);
  for(i=0;i<b;i++){
    if(i!=b-1)printf("%d ",hairetu[i]);
    else printf("%d\n",hairetu[i]);
  }
  printf("%d\n",a);
  return 0;
}
void merge(int left,int mid,int right){
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    l[i]=hairetu[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=hairetu[mid+i];
  }
  l[n1]=INFTY;
  r[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    a++;
    if(l[i]<=r[j]){
      hairetu[k]=l[i];
      i++;
    }
    else{
      hairetu[k]=r[j];
      j++;
    }
  }
}
void mergesort(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}
