#include<stdio.h>

#define N 100000

int main(){

  int input_m[N], serch_m[50000], m, n, i, j, Le, Mi, Ri, c=0, f;

  scanf("%d", &n);

  for( i = 0; i < n; i++)scanf("%d", &input_m[i]);

  scanf("%d",&m);

  for( i = 0; i < m; i++)scanf("%d", &serch_m[i]);

  for( j = 0; j < m; j++){
    f = 0;
    Le = 0;
    Ri = n;
    while(Le < Ri){
      Mi = (Le + Ri) / 2;

      if( input_m[Mi] == serch_m[j]){
	c++;
	break;
      }

      if ( input_m[Mi] < serch_m[j]){
	Le = Mi + 1;
      }

      else if( input_m[Mi] > serch_m[j]){
	Ri = Mi;
      }
    }
  }

  printf("%d\n", c);

return 0;
    }
