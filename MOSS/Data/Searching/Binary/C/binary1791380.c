#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *, int, int);

int main(){

  int i,cnt=0;
  int n,*S,q,*T;

  //入力
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  //search
  for(i=0;i<q;i++) cnt+=binarySearch(S,T[i],n);

  //表示
  printf("%d\n",cnt);


  return 0;

}
int binarySearch(int *A,int key,int n){

  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key) return 1;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }

  return 0;
}
