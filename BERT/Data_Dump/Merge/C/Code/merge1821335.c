#include <stdio.h>
#define MAX 1000000
#define INFTY 1000000000
void mergesort(int *,int,int);
void merge(int *,int,int,int);
int cnt=0;

int main(){
  int n,i,S[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  mergesort(S,0,n);

  for(i=0;i<n;i++)
    if(i!=n-1)
      printf("%d ",S[i]);
    else
      printf("%d\n%d\n",S[i],cnt);
  
  return 0;
}

void mergesort(int *S,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);
  }
}

void merge(int *S,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  int L[n1+1],R[n2+1];

  for(i=0;i<n1;i++)
    L[i]=S[left+i];
  for(i=0;i<n2;i++)
    R[i]=S[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      S[k]=L[i];
      i=i+1;
    }
    else{
      S[k]=R[j];
      j=j+1;
    }
  }
}
