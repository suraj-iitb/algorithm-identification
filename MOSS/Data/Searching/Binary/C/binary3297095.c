#include<stdio.h>

int binarysearch(int);
int s[100000000],n;


int main(){
  int t;
  int i,j,q,ct=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    ct+=binarysearch(t);
  }
  printf("%d\n",ct);
}

int binarysearch(int t){
  int left,mid,right,i,j;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==t)return 1;
    else if(s[mid]<t)left=mid+1;
    else right=mid;
  }
  return 0;
}

