#include<stdio.h>
#define MAX 10000000

int S[MAX], T[MAX];
int n;

int  linearSearch(int key){
    int i;
  for(i = 0; i < n; i++){
      if(key == S[i]){
          return key;
      }
  }
  return -1;
}

int main(void){
  int i, q, a;
  int count = 0;

  scanf("%d\n", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d\n", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for (i = 0; i < q; i++) {
    a = linearSearch(T[i]);
    if(a >= 0){
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}

