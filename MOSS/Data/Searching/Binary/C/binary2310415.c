#include <stdio.h>
#define MAX 100000
int n;
int S[MAX];
int binarySearch(int);
int main(){
  int q;
  int T[50000];
  int i,j;
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    if(binarySearch(T[i])==1)
      count++;
  }
  printf("%d\n",count);

  return 0;
}

int binarySearch(int key){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key){
      return 1;
    }
    else if(key<S[mid]){
      right=mid;
    }
    else {
      left=mid+1;
    }
  }
  return 0;
}
