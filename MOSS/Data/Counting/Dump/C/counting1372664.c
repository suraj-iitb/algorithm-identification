#include<stdio.h>
#include<stdlib.h>
#define M 10000

main(){
  int i,j,a;
   unsigned short *b,*d;
  int c[M+1];
  scanf("%d",&a);
   b = malloc(sizeof(short)*a+1);
  d =  malloc(sizeof(short)*a+1);
 for(i=0;i<=M;i++){
    c[i]=0;
  }
  for(j=0;j<a;j++){
    scanf("%d",&b[j+1]);
    c[b[j+1]]++;
  }
 
  for(i=1;i<=M;i++){
    c[i]=c[i]+c[i-1];
  }
  for(j=a;j>=1;j--){
    d[c[b[j]]]=b[j];
    c[b[j]]--;
  }
  
  for(i=1;i<a;i++){
    printf("%d ",d[i]);
  }
  printf("%d\n",d[a]);
  return 0;
  }
  
