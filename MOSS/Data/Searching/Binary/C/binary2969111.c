#include<stdio.h>
int BinarySearch(int*,int,int);
int main(){

  int i;
  int n,q;
  int count=0;

  scanf("%d",&n);
  int data1[n];
  for(i=0;i<n;i++){
    scanf("%d",&data1[i]);
  }
  
  scanf("%d",&q);
  int data2[q];
  for(i=0;i<q;i++){
    scanf("%d",&data2[i]);
  }

  for(i=0;i<q;i++){
    if(BinarySearch(data1,n,data2[i])==1){
      count++;
    }
  }
  printf("%d\n",count);
  
  return 0;
}
int BinarySearch(int *data,int n,int key){
  
  int left=0,mid,right;
  
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(key==data[mid]) return 1;
    if(key>data[mid]) left=mid+1;
    else if(key<data[mid]) right=mid;
  }
  return 0;
}

