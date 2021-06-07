#include <stdio.h>

int main(){
  int n,q,i,k,l,r,m;
  int S[100000],c = 0;

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" , S + i);
  }

  scanf("%d" ,&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d" ,&k);
    l = 0; r = n;
    while(r >= l){
      m = (l + r) / 2;

      if(S[m] == k){
	c++;
	break;
      }

      if(S[m] < k){
	l = m+1;
      }else{
	r = m-1;
      }
    }
  }
  printf("%d\n" ,c);

  return 0;
}

