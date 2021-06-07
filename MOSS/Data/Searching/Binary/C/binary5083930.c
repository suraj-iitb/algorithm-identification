#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define Q 50000

int main (){
  int i, j, k, n, q, cnt=0;
  int S[N], T[Q];
  int key, right, left, mid;
  
  scanf("%d", &n);
  if(n>100000) exit(1);

  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
    if(S[i]>1000000000) exit(2);
  }
  
  scanf("%d", &q);
  if(q>50000) exit(3);
  
  for(j=0; j<q; j++){
    scanf("%d", &T[j]);
    if(T[j]>1000000000) exit(4);
  }
  
  for(k=0; k<q; k++){
    key=T[k];
    left=0;
    right=n;

    while(left<right){
      mid=(left+right)/2;
      
      if(key==S[mid]){
	cnt++;
	break;
      }
      if(key<S[mid]) right=mid;
      else  left=mid+1;
    }
  }
  
  printf("%d\n", cnt);

  return 0;
}


