#include<stdio.h>
#include<stdlib.h>


int binarySearch(int);

int n,S[100001],q,T[50001];

int main(){
  int i,j,count=0,bs;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i]<0 || S[i]>1000000000){
      exit(1);
    }
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(T[i]<0 || T[i]>1000000000){
      exit(8);
    }
  }

  for(i=0;i<q;i++){
    bs=binarySearch(i);
    if(bs==1){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}

//Binarysearch
int binarySearch(int i){
  int left,right,mid=0;

  left=0;
  right=n;

  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==T[i]){
      return 1; //Found
    }else if(T[i]<S[mid]){
      right=mid;
    }else{
      left=mid+1;
    }
  }

  return 0; //Not found
}
