#include<stdio.h>
#define N 100000
int bs(int*, int, int);

int main(){
  int n, q, k;
  int i, j, num=0;
  int s[N]={0}, t[N][2]={0};

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &s[i]);
  scanf("%d", &q);
  for ( i = 0; i < q; i++ ) scanf("%d", &t[i][0]);

  for( i = 0 ; i < q ; i++){
    if(bs(s, t[i][0], n)!=-1){
      t[i][1] = 1;
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

int bs(int* a_p, int key, int n){
  int left  = 0;
  int right = n;
  int mid   = 0;
  while( left < right ){
    mid = (left+right)/2;
    if( key == a_p[mid]){
      return mid;
    }else if( key > a_p[mid]){
      left = mid + 1;
    }else if( key < a_p[mid]){
      right = mid;
    }
  }
  return -1;
}
