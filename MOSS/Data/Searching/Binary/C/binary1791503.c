#include <stdio.h>

#define N 100000
#define Q 50000

int main(){

  int i;
  int s[N], t[Q];
  int n, q;
  int count = 0;
  int l, mid, r;

  scanf("%d", &n);
 
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
    
  }
  
  scanf("%d", &q);
  
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
    
  }

  for(i = 0; i < q; i++){

    l = 0;
    r = n;

    while(l < r){

      mid = (l + r) / 2;

      if(s[mid] == t[i]){
	count++;
	break;
      }

      if(s[mid] < t[i]) l = mid + 1;	
      else r = mid; 

    }

  }

  printf("%d\n", count);

  return 0;
}
