#include<stdio.h>
#include<stdlib.h>
#define S     500000
#define SENT  1000000001  // STNTINEL

int cmpCount = 0;
/*
How to test
% diff <(./a.out < b1in.txt) <(cat b1out.txt) 

  for( i=0 ; i < n ; i++){
    fprintf(stderr, "%d: C2[%d] = %c%c \n" ,__LINE__ ,i ,C2[i].suit ,C2[i].value );
  }

 */

void merge(int* a_p, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int* l_p;
  int* r_p;

  // fprintf(stderr, "%d: left=%d mid=%d right=%d \n"
  //     ,__LINE__ ,left ,mid ,right );

  l_p = (int*)malloc(sizeof(int)*(n1+1));
  r_p = (int*)malloc(sizeof(int)*(n2+1));

  for( i = 0 ; i <= (n1-1) ; i++){
    l_p[i] = a_p[ left + i ];
  }
  for( i = 0 ; i <= (n2-1) ; i++){
    r_p[i] = a_p[ mid + i ];
  }
  l_p[n1] = SENT;
  r_p[n2] = SENT;
 
  i = 0; j =0;
  for( k = left ; k <= (right-1) ; k++){
    if( l_p[i] <= r_p[j] ){
      a_p[k] = l_p[i];
      i++;
    }else{
      a_p[k] = r_p[j];
      j++;
    }
    cmpCount++;
  }

  free(l_p);
  free(r_p);
}

void mergeSort(int* a_p, int left, int right){
  int mid;
  // fprintf(stderr, "%d: left=%d  right=%d \n"
  //     ,__LINE__,left    ,right );
  if( (left+1) < right ){
    mid = (left + right)/2;
    mergeSort(a_p, left, mid);
    mergeSort(a_p, mid, right);
    merge(a_p, left, mid, right);
  }
}

int main(){
  int i,j;
  int n;
  int s[S];

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &s[i]);

  mergeSort(s, 0, n);
  for(i = 0; i < n ; i++){
    printf("%d" ,s[i]);
    if( i < (n-1) ){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n" ,cmpCount);
  
  return 0; // Don't forget return 0
}
