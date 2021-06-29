#include <stdio.h>
#define N 100000
#define Q 50000

main(){
  int i, n, q, c, left, right, mid;
  int s[N], t[Q];

  scanf("%d", &n);

  for( i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for( i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  c = 0;
  
  for( i = 0; i < q; i++){

    left = 0;
    right = n;

    while( left < right ){
      
      mid = ( left + right )/2;
      
      if( s[mid] == t[i] ){
	c++;
	break;
      }
      
      else if( s[mid] > t[i] ){
	right = mid;
      }
      
    else left = mid + 1;
    }
  }
  
  printf("%d\n", c);
  
  return 0;

}
