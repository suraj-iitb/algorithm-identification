#include<stdio.h>
#include<stdlib.h>

int binarySearch(int*,int);

int n;
  
int main(){
  int i,q,*S,*T,C=0;
  scanf("%d",&n);
  S=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int*)malloc(sizeof(int)*(q+1));
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    C+=binarySearch(S,T[i]);
  }
  printf("%d\n",C);
  return 0;
}

int binarySearch(int *S,int key){
  int left=0;
  int right;
  int mid;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(key==S[mid])
      return 1;
    if(key>S[mid])
      left=mid+1;
    else if(key<S[mid])
      right=mid;
  }
  return 0;
}
