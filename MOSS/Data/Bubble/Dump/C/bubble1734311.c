#include<stdio.h>
#define N 100

void swap(int*, int*);
void pr(int*, int);

int main(){
  int n, i, j, k;
  int t=0; // times
  int a[N];

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

  for( i = 0 ; i < n ; i++){
    for(j = n-1 ; j > i ; j--){
      if( a[j] < a[j-1] ){
	swap(&a[j] ,&a[j-1]);
	t++;
      }
    }
  }

  pr(a,n);
  printf("%d\n" ,t);
  return 0;
}

void swap(int *a_p, int *b_p){
  int k;
  k    = *a_p;
  *a_p = *b_p;
  *b_p = k;
}

void pr(int *a_p, int n){
  int i;
  for( i = 0 ; i < n-1 ; i++ ){
    printf("%d " ,a_p[i]);
  }
  printf("%d" , a_p[n-1]);
  printf("\n");
}
