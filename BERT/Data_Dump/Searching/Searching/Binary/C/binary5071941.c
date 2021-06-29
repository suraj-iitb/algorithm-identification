#include <stdio.h>

#define NOT_FOUND 0

int binarySearch(int *,int,int);

int main(){
  int i,n,q,a,sum=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[n];
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    a=binarySearch(S,T[i],n);
    if(a!=0) sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int binarySearch(int *S,int key,int n){
  int left = 0,mid;
  int right = n;
  if(S[0]==key) return 1;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key)
      return mid;
    else if(key < S[mid])
      right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}
