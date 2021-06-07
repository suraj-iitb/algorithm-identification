#include <stdio.h>
#define N 100000
int n,cnt=0;
int BinarySearch(int*,int);
int main(){
  int i,m,S[N],T[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&m);
   for(i=0;i<m;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<m;i++){
    BinarySearch(S,T[i]);
  }
    printf("%d\n",cnt);
  return 0;
}
int BinarySearch(int *A,int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key){
      cnt++;
      return mid;
    }
    else if(key<A[mid])right = mid;
    else left = mid + 1;
  }
    return 0;
  }

