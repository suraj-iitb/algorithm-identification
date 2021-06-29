#include <stdio.h>
#define Ns 10000
#define Nt 500

int linearSearch(int, int*, int);


int main(){

  int n, q, key, result, count=0;
  int i, j;
  int S[Ns], T[Nt];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
  }
   
  for(i=0; i<q; i++){
    key=T[i];
    //printf("key=%d\n", key);
    result=linearSearch(n, S, key);
    //printf("result=%d\n", result);
    if(result!= -1) count++;
  }
  printf("%d\n", count);
  return 0;
}
int linearSearch(int n, int S[], int key){

  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n) return -1;
  }
  return i;

}

