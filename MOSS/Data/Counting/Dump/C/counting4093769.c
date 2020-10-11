#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10000

int main(){
  int i,j,num;
  int array[MAXNUM+1];
  unsigned short *in,*out;
  scanf("%d",&num);
  in=malloc(sizeof(short)*num+1);
  out=malloc(sizeof(short)*num+1);

  for(i=0;i<=MAXNUM;i++) array[i]=0;
  
  for(i=0;i<num;i++) scanf("%hu",&in[i+1]);
  for(j=1;j<=num;j++) array[in[j]]++;
  for(i=1;i<=MAXNUM;i++) array[i]=array[i]+array[i-1];
  
  /*downto*/
  for(j=num;j>=1;j--){
    out[array[in[j]]]=in[j];
    array[in[j]]--;
  }
  for(i=0;i<num;i++){
    if(i>0)printf (" ");
    printf("%d",out[i+1]);
  }
  printf("\n");
  return 0;
}

