#include<stdio.h>

int binarySearch(int,int *,int);

int main(){
  int S[100000],T[50000],n,q;
  int i,res=0;

  scanf("%d",&n);
  if (n<=100000){
    for(i=0; i<n; i++)scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  if (q<=50000){
    for(i=0; i<q; i++){
      scanf("%d",&T[i]);
      res += binarySearch(n,S,T[i]);
    }
  }

  printf("%d\n",res);

  return 0;
}

int binarySearch(int n,int *S,int key)
{
  int left=0,right=n,mid;

  while(left<right){
    mid = (left+right)/2;
    if (S[mid] == key) return 1;
    if (key < S[mid]) right = mid;
    else if (key > S[mid]) left = mid + 1;
  }

  return 0; 
}

