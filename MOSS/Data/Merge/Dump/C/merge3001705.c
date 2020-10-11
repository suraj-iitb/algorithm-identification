#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000
#define max 500001
void merges(int*,int,int,int);
void mergesorts(int*,int,int);
int count=0;
int n;
int main(){
  int mid;
  int right;
  int left;
  int list[max];
  scanf("%d",&n);
  mid=(n-1)/2;
  left=0;
  right=n;
  int i;
  for(i=0;i<n;i++)scanf("%d",&list[i]);
  mergesorts(list,left,right);
  for(i=0;i<n;i++)printf("%d%c",list[i],((i<n-1)?' ':'\n'));
  printf("%d\n",count);
  return 0;
}
void merges(int* list,int left,int mid,int right){
  int i;
  int j;
  int k;
  int m1=mid-left;
  int m2=right-mid;
  int n1[m1+1];
  int n2[m2+1];
  for(i=0;i<m1;i++)n1[i]=list[left+i];
  for(i=0;i<m2;i++)n2[i]=list[mid+i];
  n1[m1]=INFTY;
  n2[m2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(n1[i]<=n2[j]){
      list[k]=n1[i];
      i++;
    }
    else{
      list[k]=n2[j];
      j++;
    }
    count++;
  }
}
void mergesorts(int *list,int left,int right){
int mid;
if(left+1<right){
mid=(left+right)/2;
mergesorts(list,left,mid);
mergesorts(list,mid,right);
merges(list,left,mid,right);
}
}

