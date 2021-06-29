#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,i,k=1,a=0,count=0;
  int *raw;

  scanf("%d",&n);

  if(1>n || n > 100 ) exit(8);

  raw = (int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",raw+i);
    if(0 > raw[i] ||100 <  raw[i]) exit(8);
  }

  while(k==1){

    k = 0;
    for(i=n-1;i>=1;i--){

      if(raw[i]<raw[i-1]){
	a=raw[i];
	raw[i]=raw[i-1];
	raw[i-1]=a;
	count++;
	k = 1;
      }
    }
  }

  for(i = 0; i < n; i++){
    if(i)printf(" ");
    printf("%d",raw[i]);
  }
  printf("\n%d\n",count);
  free(raw);
  return 0;
}
  

