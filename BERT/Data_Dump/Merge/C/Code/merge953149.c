#include<stdio.h>
#include<limits.h>
#define MAX 500000

int n,S[MAX];
int cnt=0;

void Merge(int S[],int left,int mid, int right){
  int i,j,k;
  int n1,n2;
  int L[MAX],R[MAX];
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++) L[i]=S[left+i];
  for(i=0;i<n2;i++) R[i]=S[mid+i];

  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0,j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      cnt++;
      S[k]=L[i];
      i++;
    }else{
      cnt++;
      S[k]=R[j];
      j++;
    }
  }      
}

void Merge_Sort(int S[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    Merge_Sort(S,left,mid);
    Merge_Sort(S,mid,right);
    Merge(S,left,mid,right);
  }
}

int main(){
  int i,n;
  int left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  left = 0;
  right = n;
  Merge_Sort(S,left,right);

  printf("%d ",S[0]);
  for(i=1;i<n-1;i++) printf("%d ",S[i]);
  printf("%d\n%d\n",S[n-1],cnt);
  return 0;
}
  
