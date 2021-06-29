#include <stdio.h>
#include <stdlib.h>
#define nmax 100000
#define qmax 50000

int main(){
  int i,j;
  int n,q;
  int left = 0;
  int right;
  int mid;
  int S[nmax];
  int T[qmax];
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
    right = n;
    left = 0;
  while(left<right){
    mid = (left + right)/2;
    if(S[mid] == T[i]){
      count++;
      break;
    }
    else if(T[i] < S[mid]) right = mid;
    else left = mid+1;
  }
  }
  printf("%d\n",count);

  
}
