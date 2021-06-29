#include <stdio.h>

int binarySearch(int,int *,int);

int main()
{
  int n,q,i,j,cnt=0,re;
  
  scanf("%d",&n);
  int s[n];
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  } 
  scanf("%d",&q);
  int t[q];
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0;i<q;i++){
    if(binarySearch(n,s,t[i])==0){
      cnt++;
    }
    
  }
  printf("%d\n",cnt);
  
  
  return 0;
}


int binarySearch(int n,int *A,int key){
  int left,right,mid;
  left=0;
  right=n;

  
  
  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid]){
      return 0;
    }
    else if(key>A[mid]){
      left=mid+1;
    }
    else if(key<A[mid]){
      right=mid;
    }
  }
  return 1;
}

