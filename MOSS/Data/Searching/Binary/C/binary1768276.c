#include<stdio.h>

int n,S[100000];

int binarySearch(int);

int main(){
  int i, q, count=0, key, T[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    key=T[i];
    if(binarySearch(key)==1)count++;
  }
  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int key){
  int left=0, right=n, mid;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key)return 1;
    else if(key>S[mid])left=mid+1;
    else right=mid;
  }
  return 0;
}
