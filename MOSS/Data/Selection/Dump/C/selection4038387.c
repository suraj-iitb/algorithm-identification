#include<stdio.h>

int main(){
  int n[100],gyou,i,j,m,change = 0,minj;

  scanf("%d",&gyou);

  for(i = 0;i < gyou;i++){
    scanf("%d",&n[i]);
  }

  for(i = 0;i < gyou;i++){
    minj = i;

    for(j = i;j < gyou;j++){
      if(n[j] < n[minj]){
	minj = j;
      }
    }
    m = n[i];
    n[i] = n[minj];
    n[minj] = m;
    if(i != minj) change++;
  }

  for(i = 0;i < gyou;i++){
    if(i > 0) printf(" ");
    printf("%d",n[i]);
  }

  printf("\n");
  printf("%d\n",change);

  return 0;
}
