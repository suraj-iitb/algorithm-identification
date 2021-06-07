#include <stdio.h>

int main(void) {
  int i,n,answer=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    }
  int q;
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    }
    
    
  for(i = 0; i < q; i++){
    int right = n;
    int left = 0;
    int mid;
    while(left < right){
      mid = (left + right) / 2;
      if(S[mid] == T[i]){
    answer++;
    break;
      }else if(S[mid] > T[i]){
    right = mid;
      }else{
    left = mid+1;
      }
    }
  }
    
  printf("%d\n", answer);
  return 0;
}
