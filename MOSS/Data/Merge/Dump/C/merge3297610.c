#include<stdio.h>
#define INFINITY 1000000000
int count=0;
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,k,j;
  n1=mid-left;
  n2=right-mid;

  int l[n1+1],r[n2+1];

  for(i=0;i<n1;i++)l[i]=A[left+i];
  for(i=0;i<n2;i++)r[i]=A[mid+i];
  l[n1]=INFINITY;
  r[n2]=INFINITY;
  i=j=0;
  count+=right-left;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      A[k]=l[i];
      i+=1;
    }
    else {
      A[k]=r[j];
      j+=1;
    }

  }
}

void mergesort(int A[],int left,int right){

  int mid,i=0;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int n,s[500000],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  mergesort(s,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",s[i]);
  }
  printf("%d\n%d\n",s[n-1],count);
  return 0;
}

