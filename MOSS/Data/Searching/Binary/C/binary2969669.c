#include <stdio.h>

#define n 100000
#define q 50000

int main(){

  int a,b,i,left,right,mid;

  int count = 0;
  
  int S[n],T[q];
  
  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&b);

  for(i=0;i<b;i++){
    scanf("%d",&T[i]);
    
    left = 0;
    right = a;

    while(left < right){
      
      mid = (left + right) / 2;
      if(S[mid] == T[i]){
	count++;
	break;
      }

      if(S[mid] < T[i]){
	left = mid + 1;
      }

      else if(S[mid] > T[i]){
	right = mid;
      }

    }
  }

  printf("%d\n",count);

  return 0;
}

