#include<stdio.h>

int linearSearch(int a[],int n,int key){
  int i=0;
  a[n]=key;
  while(a[i]!=key)i++;
  if(i==n){return 0;}
  else{return 1;}
}

int main(){
  int i,ary[10001],judge=0,n,key,q;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(ary,n,key))judge++;
  }
  printf("%d\n",judge);
  return 0;
}

  

