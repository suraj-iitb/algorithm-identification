#include <stdio.h>

int main(){
  int i, j, n, S[100000], q, T[50000], c=0, left, right, middle;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &T[i]);
  }
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){ 
      middle=(left+right)/2;
      if(S[middle]==T[i]){
	c++;
	break;
      }
      else if(S[middle]<T[i]){
	left=middle+1;
      }
      else if(T[i]<=S[middle]){
	right=middle;
      }
      else break;
    }
  }
  
  printf("%d\n", c);

  return 0;
}
