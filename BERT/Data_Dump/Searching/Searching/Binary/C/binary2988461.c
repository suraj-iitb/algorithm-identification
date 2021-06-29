#include<stdio.h>
#define MAX_S 100000
#define MAX_T 50000

int main(){
  int i, j, n, q, cnt=0;
  int left=0, right=0, mid=0;
  int S[MAX_S], T[MAX_T];

  scanf("%d", &n);
  right = n;
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
  }

  
  for(i=0; i<q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left+right) / 2;
      if(S[mid] == T[i]){
	cnt++;
	break;
      }
      else if(T[i] < S[mid]){
	right = mid;
      }
      else{
	left = mid+1;
      }
      //printf("left__%d, right__%d\n", left, right);
    }
  }

  printf("%d\n", cnt);
  return 0;
  
  /*
    for(i=0; i<n; i++){
    printf("%d ", S[i]);
    }printf("\n");
    for(i=0; i<q; i++){
    printf("%d ", T[i]);
    }
  */
}

