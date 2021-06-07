#include<stdio.h>

int BinarySearch(int x);

int n,S[100000];

int main(void){
  int q,i,c=0,T;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
      if(BinarySearch(T)){
        c++;
      }
    }
  printf("%d\n",c);
  return 0;
}

int BinarySearch(int x){
  int left = 0;
  int right  = n;
  int mid;
  while(left<right){
    mid = (left+right) / 2;
    if(S[mid]==x){return 1;}
    else if(x < S[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return 0;
}

