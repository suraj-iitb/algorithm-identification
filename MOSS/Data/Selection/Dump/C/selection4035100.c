#include <stdio.h>

int main(){
  int n,i,j,c = 0,minj,tmp;
  scanf("%d",&n);
  int r[n];
  for(i = 0; i < n; i++){
    scanf("%d",&r[i]);
  }
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(r[j] < r[minj]){
        minj = j;
      }
    }
    if(r[i] != r[minj]){
      tmp = r[i];
      r[i] = r[minj];
      r[minj] = tmp;
      c++;
    }
  }
  for(i = 0; i < n; i++){
    printf("%d",r[i]);
    if(i == n - 1){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",c);
  return 0;
}

