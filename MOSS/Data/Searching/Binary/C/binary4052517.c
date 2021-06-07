#include<stdio.h>

#define N 100000

int binarySearch(int*,int,int);

int main(){
  int i,j,a,n=0,m;
  int S[N],T;

  scanf("%d",&i);

  for(a=0;a<i;a++){
    scanf("%d",&S[a]);
  }

  scanf("%d",&j);

  for(a=0;a<j;a++){
    scanf("%d",&T);
    m=binarySearch(S,T,i);
    if(m==-1) continue;
    else n++;
  }

  printf("%d\n",n);
  
  return 0;
}

int binarySearch(int *A,int key,int right){
  int left=0,mid;

  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key) return mid;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }

  return -1;
}

