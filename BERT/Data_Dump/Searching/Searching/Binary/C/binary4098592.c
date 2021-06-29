#include<stdio.h>

int main(){
  int n,q,i,j,left,right,mid,cnt=0;
  int S[100000];
  int T[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(j=0;j<q;j++)
    scanf("%d",&T[j]);
  
  left=0;
  right=n;
  j=0;
  while(j!=q){
    mid=(left+right)/2;
    if(T[j]==S[mid]){
      cnt++;
      j++;
      left=0;
      right=n;
    }else if(T[j]>S[mid]){
      left=mid+1;
    }else if(T[j]<S[mid]){
      right=mid;
    }
    if(j!=q && left>=right){
      j++;
      left=0;
      right=n;
    }
  }
  printf("%d\n",cnt);
  return 0;
}

