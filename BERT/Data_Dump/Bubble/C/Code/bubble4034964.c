#include <stdio.h>

int main(){
  int n,i,j,c = 0,tmp;
  scanf("%d",&n);
  int r[n];
  for(i = 0; i < n; i++){
    scanf("%d",&r[i]);
  }
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if(r[j] < r[j - 1]){
        tmp = r[j];
        r[j] = r[j - 1];
        r[j - 1] = tmp;
        c++;
      }
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

