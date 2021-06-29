#include<stdio.h>

#define N 10000

int main(){

  int input_m[N], serch_m[500], m, n, i, j, c=0;

  scanf("%d", &n);

  for( i = 0; i < n; i++)scanf("%d", &input_m[i]);

  scanf("%d",&m);

  for( i = 0; i < m; i++)scanf("%d", &serch_m[i]);

  for( j = 0; j < m; j ++){
    for( i = 0; i < n; i++){
      if(input_m[i] == serch_m[j]){
	c++;
	break;
      }
    }
}

    printf("%d\n", c);

    return 0;
  }
