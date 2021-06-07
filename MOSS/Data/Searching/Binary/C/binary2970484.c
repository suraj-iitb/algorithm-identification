#include<stdio.h>

int binarySearch(int A[],int n,int key){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid])return 1;
    if(key>A[mid])left=mid+1;
    if(key<A[mid])right=mid;
    }
  return 0;
}



int main(){
  int n,S[100000],q,T,i,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(binarySearch(S,n,T)==1)sum++;
  }
  printf("%d\n",sum);
  return 0;
}

