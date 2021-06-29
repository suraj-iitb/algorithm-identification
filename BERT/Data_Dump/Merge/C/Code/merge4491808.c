#include<stdio.h>
#define MAX 500000
#define INFTY 1000000001
int  H[MAX];

int merge(int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right -mid;
  int L[n1],R[n2];
  int i;
  static int sum=0;
  for(i=0;i<n1;i++)L[i]=H[left+i];
  for(i=0;i<n2;i++)R[i]=H[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  int j=0,k;
  for(k=left;k<right;k++){
    if(L[i]<=R[j])H[k]=L[i++];
    else H[k]=R[j++];
    sum++;
  }
  return sum;
}

int mergesort(int left,int right){
  int a;
  if (left+1<right){
    int mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    a=merge(left,mid,right);
  }
  return a;
}



int main(){
  int i,n,cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&H[i]);
  cnt=mergesort(0,i);
  for(i=0;i<n;i++){
    if(i!=n-1)printf("%d ",H[i]);
    else printf("%d\n",H[i]);
  }
  printf("%d\n",cnt);
  return 0;
  
}


