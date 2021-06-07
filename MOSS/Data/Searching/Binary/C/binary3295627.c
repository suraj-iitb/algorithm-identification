#include <stdio.h>
#define N 100000
#define Q 50000

int S[N];
int binarySearch(int ,int );

int main(){
  int n,q,i,j,count=0,a;
  int T[Q];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    a = binarySearch(T[i],n);
    if(a == 0)count++;
  }

  printf("%d\n",count);

  return 0;
}

int binarySearch(int x,int n){
  int left,right,mid;
  
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == x){
      return 0;
    }
    else if(x < S[mid]){
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
  return 1;
}

