#include <stdio.h>
int L[500000],R[500000];
int cnt=0,stn=2000000000;

void merge(int s[],int n,int left,int mid,int right);
void mergesort(int s[],int n,int left,int right);

int main(){
  int i,n;
  int s[500000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]); 

  mergesort(s,n,0,n);

  for(i=0;i<n-1;i++) printf("%d ",s[i]);
  printf("%d",s[n-1]);
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

void merge(int s[],int n,int left,int mid,int right){
  int i,j=0,k;  
  int n1=mid-left;
  int n2=right-mid;

  for(i=0;i<n1;i++) L[i]=s[left+i];
  for(i=0;i<n2;i++) R[i]=s[mid+i];
  L[n1]=R[n2]=stn;
  i=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      s[k]=L[i++];
    }
    else s[k]=R[j++];
  }
}

void mergesort(int s[],int n,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergesort(s,n,left,mid);
    mergesort(s,n,mid,right);
    merge(s,n,left,mid,right);
  }
}
