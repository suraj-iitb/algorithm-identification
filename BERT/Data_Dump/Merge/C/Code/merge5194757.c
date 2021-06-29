#include<stdio.h>
#define INF 2000000000
void MS(int,int);
void merge(int,int,int);
int S[5000000];
int cnt=0;
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  MS(0,n);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}
void MS(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    MS(left,mid);
    MS(mid,right);
    merge(left,mid,right);
  }
}
void merge(int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=S[left+i];
  }
  L[n1]=INF;
  for(i=0;i<n2;i++){
    R[i]=S[mid+i];
  }
  R[n2]=INF;
  i=0;j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
      cnt++;
    }
    else{
      S[k]=R[j];
      j++;
      cnt++;
    }
  }
}

