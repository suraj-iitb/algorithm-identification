#include<stdio.h>

int main(){

  int n,i,j,k,temp,x[100],min,flag=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }

  for(i=0;i<n;i++){
    min = x[i];
    k = i;
    for(j=i+1;j<n;j++){
      if(x[j] < min){
       	min = x[j];
	k = j;
      }
    }
    if(k!=i){
      temp = x[i];
      x[i] = x[k];
      x[k] = temp;
      flag++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",x[i]);
    if(i==n-1){
      break;
    }
      printf(" ");
  }
  printf("\n");
  printf("%d",flag);
  printf("\n");

  return 0;
}
