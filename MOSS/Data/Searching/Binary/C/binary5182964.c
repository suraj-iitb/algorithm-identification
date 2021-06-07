#include<stdio.h>

int binarySearch(int);

int n,S[100000],T[50000];

int main(){
  int i,q,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    if((binarySearch(T[i]))!=-1)cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int key){
  int middle,left=0,right=n;
  while(left<right){
    middle=(left+right)/2;
    if(S[middle]==key)return 1;
    else if(S[middle]>key)right=middle;
    else left=middle+1;
  }
  return -1;
}
