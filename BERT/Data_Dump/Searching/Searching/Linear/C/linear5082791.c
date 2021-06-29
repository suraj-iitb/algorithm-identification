#include<stdio.h>

int main(void){

  int i,j,n,q;
  int count=0;
  int S[100000],T[100000];

  //入力1
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
  //入力2
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  
  for(i=0; i<q; i++){
    for(j=0; j<n; j++){

      if( T[i] == S[j] ){
	count++;
	break;
      }

    }
  }

  //出力
  printf("%d\n",count);

  return 0;
}

