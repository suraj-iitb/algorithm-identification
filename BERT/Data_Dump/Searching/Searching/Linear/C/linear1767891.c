#include<stdio.h>
#define N 10000

int main(){
  int n, q;
  int i, j, num=0;
  int s[N]={0}, t[N][2]={0};

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &s[i]);
  scanf("%d", &q);
  for ( i = 0; i < q; i++ ) scanf("%d", &t[i][0]);

  for( i = 0 ; i < n ; i++){
    for( j = 0; j < q ; j++){
      if( s[i] == t[j][0] ){
        t[j][1] = 1;
      }
    }
  }

  for( j=0 ; j < q ; j++){
    if(t[j][1]==1){
      num++;
    }
  }

  printf("%d\n" ,num);
  return 0; // Don't forget return 0
}
