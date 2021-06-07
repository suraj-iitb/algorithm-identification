#include<stdio.h>

int linearSearch(int*, int, int);

int main() {
  int i, sl, tl, arrayS[10000], arrayT[500], result=0;

  scanf("%d", &sl);
  for(i=0 ; i<sl ; i++) { scanf("%d", &arrayS[i]); }

  scanf("%d", &tl);
  for(i=0 ; i<tl ; i++) { scanf("%d", &arrayT[i]); }

  for(i=0 ; i<tl ; i++) {
    if(linearSearch(arrayS, sl, arrayT[i])) { result++; }
  }
  
  printf("%d\n", result);
  return 0;
}

int linearSearch(int* array, int l, int key) {
  int i;

  for(i=0 ; i < l; i++){
    if(array[i] == key) { return 1; }
  }
  
  return 0;
}

