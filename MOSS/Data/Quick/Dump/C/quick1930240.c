#include<stdio.h>
#define N 100000
typedef struct{
  int  num;
  char mk; // mark
  int order; // original order
} card_t;

void swap(card_t *a_p, card_t *b_p){
  card_t k;
  k    = *a_p;
  *a_p = *b_p;
  *b_p = k;
}


int prt(card_t* a_p, int p, int r ){
  int j;
  int x = a_p[r].num;
  int i = p-1;

  for( j = p ; j <= (r-1) ; j++){
    if( a_p[j].num <= x){
      i++;
      swap((a_p+i) ,(a_p+j));
    }
  } 
  swap( (a_p+i+1) ,(a_p+r));
  
  return i+1;
}

void qsort(card_t* a_p, int p, int r){
  int q;
  if( p < r ){
    q = prt(a_p, p, r);
    qsort(a_p, p, q-1);
    qsort(a_p, q+1, r);
  }
}


int main(){
  int n, i, j, k;
  int q;
  int nsf = 0; // not stable flag
  card_t a[N] = {0};
  
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf(" %c%d", &(a[i].mk) ,&(a[i].num) );
    a[i].order = i;
  }

  qsort(a,0,n-1);  

  /* for debug
  for( i=0 ; i<n ; i++){
    printf("a[%i].mk = %c .num = %d .order = %d \n"
	   ,i ,a[i].mk ,a[i].num ,a[i].order );
  }
  */

  for( i = 0 ; i < (n-1) ; i++){
    if( a[i].num == a[i+1].num && a[i].order > a[i+1].order){
      nsf = 1;
      printf("Not stable\n");
      break;
    } 
  }
  if( nsf == 0){
    printf("Stable\n");
  }

  for( i = 0; i < n ; i++){
    printf("%c %d\n" ,a[i].mk ,a[i].num );
  }

  return 0; // Don't forget return 0
}
