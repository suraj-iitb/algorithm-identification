#include<stdio.h>

int s[500001],sum=0;

void mergesort(int *,int,int);
void merge(int *,int,int,int);
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  mergesort(s,0,n);
  for(i=0;i<n;i++){
    printf("%d",s[i]);
    if(i==n-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  printf("%d\n",sum);
}

void mergesort(int s[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(s,left,mid);
    mergesort(s,mid,right);
    merge(s,left,mid,right);
  }
}

void merge(int s[],int left,int mid,int right){
  int n1,n2,L[mid-left],R[right-mid],i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=s[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=s[mid+i];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    sum++;
    if(L[i]<=R[j]){
      s[k]=L[i];
      i++;
    }else{
      s[k]=R[j];
      j++;
    }
  }
}


