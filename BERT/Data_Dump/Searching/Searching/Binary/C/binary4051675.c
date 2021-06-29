#include <stdio.h>

int main(){
  int n,q,i,key,lb,ub,mid;
  int S[100000],ans = 0;

  scanf("%d" ,&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d" , S + i);
  }

  scanf("%d" ,&q);
  
  for(i = 0 ; i < q ; i++){
    
    scanf("%d" ,&key);
    lb = 0; ub = n;
    
    while(ub >= lb){
      mid = (lb + ub) / 2;

      if(S[mid] == key){
	ans++;
	break;
      }

      if(S[mid] < key){
	lb = mid+1;
      }
      else{
	ub = mid-1;
      }
    }
  }
  printf("%d\n" ,ans);

  return 0;
}

