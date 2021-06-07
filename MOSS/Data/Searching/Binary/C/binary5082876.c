#include<stdio.h>

#define FOUND 1;
#define N_FOUND 0;

int g_key,g_S[100000];

int binary_search(int);

int main(void){

  int i,n,q,k;
  int count=0;
  int T[100000];

  //入力1
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &g_S[i]);
  }
  //入力2
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  //
  for(i=0; i<q; i++){
    g_key = T[i];
    k = binary_search(n);

    if( k == 1 ){
      count++;
    }
 
  }
  
  //出力
  printf("%d\n",count);

  return 0;
}


int binary_search(int right){

  int left=0,mid;
  
  while( left < right ){

    mid = (left+right)/2;
    
    if( g_S[mid] == g_key ){
      return FOUND;
    }

    else if( g_key < g_S[mid] ){
      right = mid;
    }

    else{
      left = mid + 1;
    }
    
  }
  
  return N_FOUND;
}

