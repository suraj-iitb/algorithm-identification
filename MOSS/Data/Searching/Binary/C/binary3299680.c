#include<stdio.h>
int binarysearch(int);

int n,S[100000000];

int main()
{
  int q,t,c=0;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarysearch(t)==1) c++; 
  }
  printf("%d\n",c);
  return 0;
}

int binarysearch(int key){
  int left=0,right=n,mid;

  while(left<right){
    mid = (left + right)/2;
    if(key==S[mid]) return 1;//発見
    
    if(key>S[mid]) left = mid+1;
    else if(key<S[mid]) right = mid;
  }
  return 0;
}

