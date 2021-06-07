#include <stdio.h>
#include <stdlib.h>
int n, l, j, u, k, tmp;
int list[100][100];
int lengthlist[100];

void search(int y, int length){
  int i;
  length++;
  lengthlist[y] = length;


  for( i = 0 ; i < n ; i++){
    if( list[y][i] == 1 ){
      if( lengthlist[i] <= length && lengthlist[i] >= 0 ){
        continue;
      }
      search(i, length);
    }
  }
}

int main(){
  scanf("%d", &n);
  for(l = 0 ; l < n ; l++){
    scanf("%d", &u);
    scanf("%d", &k);
    for( j = 0 ; j < k ; j++){
      scanf("%d", &tmp);
      list[u-1][tmp-1] = 1;
    }
  }
  for( l = 0 ; l < n ; l++){
    lengthlist[l] = -1;
  }
  search(0, -1);

  for(j = 0 ; j < n ; j++){
    printf("%d %d\n", j+1, lengthlist[j]);
  }

  return 0;
}

