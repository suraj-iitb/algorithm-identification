#include <stdio.h>

int main(){
  int bubble[100];
  int n,i,j,flag,d,t=0;

  scanf("%d",&n);
  for(i=0; i < n; i++){
    scanf("%d",&bubble[i]);
  }

  flag =1;
  while(flag){
    flag=0;
    for(j=n-1; j >=1; j--){
      if(bubble[j] < bubble[j-1]){
	d=bubble[j-1];
	bubble[j-1]=bubble[j];
	bubble[j]=d;
	flag=1;
	t++;
      }
    }
  }

  for(i=0; i < n; i++){
    printf("%d",bubble[i]);
    if(i==n-1){
      printf("\n");
    }
    else
      printf(" ");
  }
  printf("%d\n",t);

  return 0;
}
