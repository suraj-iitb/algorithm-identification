#include<stdio.h>
#define N 2000001
#define K 20001

/*
How to test
% diff <(./a.out < b1in.txt) <(cat b1out.txt) 

  for( i=0 ; i < n ; i++){
    fprintf(stderr, "%d: C2[%d] = %c%c \n" ,__LINE__ ,i ,C2[i].suit ,C2[i].value );
  }

 */

void csort(short* a_p, short* b_p, const int n){
  int i, j;
  int c[K] = {0};
  
  for( j = 1 ; j <= n ; j++){
    // fprintf(stderr, "%d: a_p[%d] = %d \n" ,__LINE__ ,j ,a_p[j] );
    c[a_p[j]]++;
  }

  
  for( i = 1 ; i < K ; i++){
    // fprintf(stderr, "%d: c[%d] = %d  c[%d] = %d \n" ,__LINE__ ,i ,c[i] ,i-1 ,c[i-1] );
    c[i] = c[i] + c[i-1];
    //  fprintf(stderr, "%d: c[%d] = %d  c[%d] = %d \n" ,__LINE__ ,i ,c[i] ,i-1 ,c[i-1] );
  }

  for( j = n ; j > 0 ; j-- ){
    b_p[c[a_p[j]]] = a_p[j];
    c[a_p[j]]--;
    // fprintf(stderr, "%d: a_p[%d] = %d  b_p[%d] = %d  c[%d] = %d \n" 
    //    ,__LINE__        ,j ,a_p[j]    ,j ,b_p[j]  ,j ,c[j] );

  }

  return;
}

int main(){
  int n, i, j, k;
  short a[N];
  short b[N];
  
  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &a[i]);

  csort(a,b,n);  
  for( i = 1 ; i <= n ; i++ ){
    printf("%d" ,b[i]);
    if( i != (n) ){
      printf(" ");
    }
  }
  printf("\n");

  return 0; // Don't forget return 0
}
