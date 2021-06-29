#include<stdio.h>
#include<stdlib.h>
int binarySearch(int n,int key,int *S);
int main(){
  int n,*S,q,*T,i,N,count=0;
  scanf("%d\n",&n);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d\n",&q);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    N=binarySearch(n,T[i],S);
    if(N!=7777){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int n,int key,int *S){
  int mid,left=0,right=n;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key){
      return mid;
    }
    else if(key<S[mid]){
      right=mid;
    }
    else{
      left=mid+1;
    }
  }
  return 7777;
}

