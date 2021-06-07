#include<stdio.h>

int Btree(int[],int,int);

int main(){
  int n,data[100001],q,key,i,total=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&data[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Btree(data,key,n))total++;
  }
  printf("%d\n",total);
  return 0;
}

int Btree(int data[],int key,int n){
  int left,right,mid;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
  if(data[mid]==key)return 1;
  else if(key<data[mid])right=mid;
  else left=mid+1;
  }
  return 0;
}

