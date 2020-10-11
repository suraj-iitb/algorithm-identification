#include<stdio.h>

#define N 500000
#define INF 1000000000

int c;

void merge( int *, int , int , int );
void mergeSort( int *, int , int );

int main(){

  int n, i, arr[N];

  scanf("%d", &n);

  for( i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  mergeSort( arr, 0, n);

  for( i = 0; i < n; i++){

    printf("%d", arr[i]);

    if( i != n-1)printf(" ");

  }

  printf("\n%d\n", c);

  return 0;
}

void merge(int *arr, int l, int m, int r){

  int le, ri, i, j, k;
  int L[N], R[N];
  le = m - l;
  ri = r - m;
  // ?´°??????
  for( i = 0; i < le; i++){

    L[i] = arr[l + i];

  }

  for( i = 0; i < ri; i++){

    R[i] = arr[m + i];

  }

  L[le] = INF;
  R[ri] = INF;

  i = j = 0;
  //??????
  for( k = l; k < r; k++){
    c++;
    if(L[i] <= R[j]){

      arr[k] = L[i];
      i++;

    }
    else{
 
      arr[k] = R[j];
      j++;

    }
  }
}

void mergeSort( int *arr, int l, int r){

  int m;

  if(l + 1 < r){
    m = (l + r) / 2;

    mergeSort( arr, l, m);
    mergeSort( arr, m, r);
    merge( arr, l, m, r);
  }
}
