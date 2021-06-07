#include<stdio.h>
main(){
#define nMAX 100000
#define qMAX 50000
  int n, q, S[nMAX], T[qMAX], i, l, r, m, key, c=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  
  for(i = 0; i < q; i++){
    key = T[i];
    l = 0;
    r = n;
    while(l < r){
      m = (l+r)/2;
      if(S[m] == key){
	c++;
	break;
      }
      else if(key < S[m]){
	r = m;
      }
      else{
	l = m+1;
      }
    }
  }
  printf("%d\n", c);
  return 0;
}
