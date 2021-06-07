#include <stdio.h>

#define N 100000
#define Q 50000
#define E 1000000000

int binarysearch(int key);
int S[N];
int n=0;

main() {
  
  int q=0;
  int T[Q];
  int C=0;
  int i=0,j=0;
  
  scanf("%d",&n);
  
  if(n < 0 || N < n){
    return 0;
  }
  
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);

    if(S[i] < 0 || E < S[i]){
      return 0;
    }
  }
  
  scanf("%d",&q);
  
  if(q < 0 || Q < q){
    return 0;
  }
  
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);

     if(T[i] < 0 || E < T[i]){
      return 0;
    }
    j = binarysearch(T[i]);
    C = C+j;
  }

  printf("%d\n",C);
  
  return 0;
}

int binarysearch(int key){
  int left=0; 
  int right=n;  
  int mid; 
  
  while(right > left) {
    mid = (left+right)/2; 
    if(key == S[mid]) return 1;
    if(key > S[mid]) left = mid+1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}
