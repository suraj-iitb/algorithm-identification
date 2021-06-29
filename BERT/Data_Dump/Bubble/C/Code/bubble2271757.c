#include<stdio.h>

int main(){

  int n,x[100],i,j,temp,flag=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }

  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(x[j-1] > x[j]){
	temp = x[j];
	x[j] = x[j-1];
	x[j-1] = temp;
	flag++;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d",x[i]);
    if(i==n-1){
      break;
    }
      printf(" ");
  }
  
    
  printf("\n");
  printf("%d\n",flag);

  return 0;
}
