#include<stdio.h>
#include<stdlib.h>

#define n 100000
#define q 50000
int s[n],S;
int binary(int);

int main (){

  int i, j, t[q], cnt=0, T;

  scanf("%d", &S);

  for(i=0; i<S; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &T);

  for(j=0; j<T; j++){
    scanf("%d", &t[j]);
  }

  for(j=0; j<T; j++){
    cnt+=binary(t[j]);
  }

  printf("%d\n", cnt);

  return 0;
}

int binary(int key){

  int l=0, r, m;

  r = S;

  while(l < r ){
    m = ( r + l )/2;
    if(key==s[m])
      return 1;
    if(key>s[m])
      l = m + 1;
    else if(key<s[m])
      r = m ;
  }
  return 0;
}



