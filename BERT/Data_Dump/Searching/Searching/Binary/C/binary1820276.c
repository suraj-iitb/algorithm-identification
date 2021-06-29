#include<stdio.h>
#include<stdlib.h>

#define n 100000
#define q 50000
int s[n],S;
int binary(int);
int main (){

  int i, j, t[q], count=0, T;

  scanf("%d", &S);

  for(i=0; i<S; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &T);

  for(j=0; j<T; j++){
    scanf("%d", &t[j]);
  }

  for(j=0; j<T; j++){
    count+=binary(t[j]);
  }

  printf("%d\n", count);

  return 0;
}

int binary(int key){

  int left=0, right, mid;

  right=S;

  while(left<right){
    mid=(right+left)/2;
    if(key==s[mid])
      return 1;
    if(key>s[mid])
      left=mid+1;
    else if(key<s[mid])
      right=mid;
  }
  return 0;
}
