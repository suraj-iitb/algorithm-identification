#include<stdio.h>

int main(){
  int n[100],i,j,gyou,m,change = 0;

  scanf("%d",&gyou);

  for(i = 0;i < gyou;i++){
    scanf("%d",&n[i]);
  }

  for(i = 0;i < gyou;i++){
    for(j = gyou - 1;j >= i + 1;j--){
      if(n[j] < n[j - 1]){
	m = n[j];
	n[j] = n[j - 1];
	n[j - 1] = m;
	change++;
      }
    }
  }

  for(i = 0;i < gyou;i++){
    if(i > 0) printf(" ");
    printf("%d",n[i]);
  }

  printf("\n");
  printf("%d\n",change);
  
  return 0;
}
