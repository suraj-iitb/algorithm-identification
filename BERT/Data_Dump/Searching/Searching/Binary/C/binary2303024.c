#include <stdio.h>
#define N 100000
#define Q 100000
int binarySearch(int a,int b);
int S[N];

int main(){
  int i,n,q,T[Q],a=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
   scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    a+=binarySearch(T[i],n);
  }

  printf("%d\n",a);

  return 0;
}

int binarySearch(int t,int n){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == t)    return 1;
    else if(t < S[mid])right=mid;
    else left = mid +1;
  }
  return 0;
}
  
