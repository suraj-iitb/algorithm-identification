#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

#define INFTY 2147483647


void swapInt( int *n1, int *n2) {
  
  int tmp;
  
  tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
  
}

void swapChar( char *c1, char *c2) {
  
  char tmp;
  
  tmp = *c1;
  *c1 = *c2;
  *c2 = tmp;
  
}


int partition( int *a, char *c, int p, int r) {
  
  int x;
  int i, j;
  
  x = a[r];
  i = p-1;
  
  for( j=p; j<r; j++) {
    if( a[j] <= x ) {
      i++;
      swapInt( &a[i], &a[j]);
      swapChar( &c[i], &c[j]);
    }
  }
  swapInt( &a[i+1], &a[r]);
  swapChar( &c[i+1], &c[r]);
  return i+1;
  
}


quickSort(int*  a, char* c, int p, int r) {
  
  int q;
  
  if( p < r) {
    q = partition( a, c, p, r);
    quickSort( a, c, p, q-1);
    quickSort( a, c, q+1, r);
  }
} 


void merge( int* a, char* c, int left, int mid, int right) {
  
  int *l, *r;
  char *lc, *rc;
  int n1, n2;
  
  int i, j, k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  l = (int *)malloc(sizeof(int) *(n1+1));
  lc = (char *)malloc(sizeof(char) *(n1+1));
  r = (int *)malloc(sizeof(int) *(n2+1));
  rc = (char *)malloc(sizeof(char) *(n1+1));
  
  for( i=0; i<n1; i++) {
    l[i] = a[left+i];
    lc[i] = c[left+i];
  }
  for( i=0; i<n2; i++) {
    r[i] = a[mid+i];
    rc[i] = c[mid+i];
  }
  
  l[n1] = INFTY;
  r[n2] = INFTY;
  
  i=0;
  j=0;
  
  for( k=left; k<right; k++) {
    
    if( l[i] <= r[j]) {
      a[k] = l[i];
      c[k] = lc[i];
      i++;
    }
    else {
      a[k] = r[j];
      c[k] = rc[j];
      j++;
    }
    
  }
  
  free(l);
  free(r);
  free(lc);
  free(rc);
  
}


void mergeSort( int* a, char* c, int left, int right) {
  
  int mid;
  
  if( left+1 < right) {
    mid = ( left + right)/2;
    mergeSort( a, c, left, mid);
    mergeSort( a, c, mid, right);
    merge( a, c, left, mid, right);
  }

}


main() {
  
  int n;
  int* a, * ma;
  char* c, * mc;
  int isStable;
  
  int i;
  
  scanf("%d", &n);
  
  a = (int*)malloc( sizeof( int ) * n );
  c = (char*)malloc( sizeof( char ) * n );
  
  //マージソート用配列
  ma = (int*) malloc( sizeof( int ) * n );
  mc = (char*)malloc( sizeof( char ) * n );
  
  
  for( i=0; i<n; i++) {
    scanf(" %c %d", &c[i], &a[i]);
    mc[i] = c[i];
    ma[i] = a[i];
  }
  
  quickSort( a, c, 0, n-1);
  mergeSort( ma, mc, 0, n);

  
  isStable = true;
  for( i=0; i<n; i++) {
    if(c[i] != mc[i]) {
      isStable = false;
      break;
    }
  }
  
  
  if( isStable == true) {
    printf("Stable\n");
  }else {
    printf("Not stable\n");
  }
  
  
  for( i=0; i<n; i++) {
    printf("%c %d\n", c[i], a[i]);
  }
  
  return 0;
}
