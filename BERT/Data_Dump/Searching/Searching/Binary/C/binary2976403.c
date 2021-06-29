#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *,int,int);

int main(){
  int i,count=0;
  int n,q,T;
  int *S;

  scanf("%d",&n);
  if(0>n || n>100000)return 0;

  S = (int *)malloc(sizeof(int) * n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(0>S[i] || S[i]>1000000000)return 0;
  }

  scanf("%d",&q);
  if(0>q||q>50000)return 0;



  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(0>T || T>1000000000)return 0;
    if(binarySearch(S,n,T)==1)count++;
  }

printf("%d\n",count);

return 0;
}

int binarySearch(int S[],int n,int T){
  int left = 0,mid;
  int right = n;
  while(left<right){
    mid = (left  + right)/2;

    if(S[mid] == T)return 1;

    else if(T<S[mid])right =  mid;

    else left = mid + 1;
  }
  return 0;
}

