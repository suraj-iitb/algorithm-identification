#include <stdio.h>
#define N 100000

int main(){

  int S[N],SA[N],i,num,num2;
  int cnt = 0;
  int right,left;
  
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&S[i]);
  }
  
  int mid;
 
  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&SA[i]);
  }
  
  for(i=0;i<num2;i++){
    
  left = 0;
  right = num;

  while(left < right){
      mid = (left + right)/2;
      if(SA[i] == S[mid]) {
	cnt++;
	break;
      }
      if(SA[i] > S[mid]) left = mid +1;
      else if(SA[i] < S[mid]) right = mid;
    }
  }

  printf("%d\n",cnt);


  return 0;
}

