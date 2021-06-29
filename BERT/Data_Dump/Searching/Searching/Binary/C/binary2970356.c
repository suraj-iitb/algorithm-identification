#include<stdio.h>

int BinarySearch(int ary[],int n,int key){
  int l=0,m,r=n;
  while(l<r){
    m=(l+r)/2;
    if(ary[m]==key){return 1;}
    else if(key<ary[m]){r=m;}
    else{l=m+1;}
  }
  return 0;
}

int main(){
  int i,ary[1000000],judge=0,n,key,q;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(BinarySearch(ary,n,key))judge++;
  }
  printf("%d\n",judge);
  return 0;
}

