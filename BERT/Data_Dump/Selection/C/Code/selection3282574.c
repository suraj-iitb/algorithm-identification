#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,i,j,minj=0,a=0,count=0;
  int *raw;

  scanf("%d",&n);

  if(1>n || n > 100 ) exit(8);

  raw = (int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",raw+i);
    if(0 > raw[i] ||100 <  raw[i]) exit(8);
  }

  for(i=0; i<n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(raw[j] < raw[minj])
	minj = j;
    }
    a = raw[i];
    raw[i]=raw[minj];
    raw[minj]=a;
    if(i != minj) count++;
    
  }
  

  for(i=0; i < n; i++){
    if(i)printf(" ");
    printf("%d",raw[i]);
  }

  printf("\n%d\n",count);

  free(raw);

  return 0;
}

