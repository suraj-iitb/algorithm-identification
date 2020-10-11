#include<stdio.h>
#include<stdlib.h>
#define N 100

int main(){
  int b,i,j,B[N],min,v,cnt=0;
  
  scanf("%d",&b);
  if(b<1 || b>100)exit(0);
  
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
    if(B[i]<0 || B[i]>100)exit(1);
  }
  for(i=0;i<b;i++){
    min=i;
    for(j=i;j<b;j++){
      if(B[j]<B[min]){
	min=j;
      }
    }
    if(min!=i){
        v=B[i];
	B[i]=B[min];
	B[min]=v;
	cnt++;
    }
  }
  for(i=0;i<b;i++){
    printf("%d",B[i]);
    if(i==b-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",cnt);
  
  return 0;
}

