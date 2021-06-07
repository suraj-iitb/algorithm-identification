#include <stdio.h>

int main(){
  int S[100000], count = 0, s, t, t0, i, j, left, right, mid;
  scanf("%d",&s);
  for(i = 0; i < s; i++) scanf("%d",&S[i]);
  scanf("%d",&t);

  for(i = 0; i < t; i++){
    left = 0;
    right = s;
    
    scanf("%d",&t0);
    while(left < right){
      mid = (right + left)/2;
      if(S[mid] == t0){
	count++;
	break;
      }
      else if(S[mid] > t0){
	right = mid;
      }
      else if(S[mid] < t0){
        left = mid + 1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
