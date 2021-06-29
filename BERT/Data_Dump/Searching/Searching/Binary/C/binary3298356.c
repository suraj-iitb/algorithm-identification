#include<stdio.h>

int bsearch(int *a,int key,int n){
  int left,right,mid;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key) return 1;
    else if(key<a[mid]) right=mid;
    else left=mid+1;
  }
  return 0;
}
  
int main(){
  int i,j,r,key,n,q,S[100000],T[50000],c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    c+=bsearch(S,T[i],n);
  }

  printf("%d\n",c);

  return 0;
}

  

