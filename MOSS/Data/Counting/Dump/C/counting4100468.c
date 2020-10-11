#include<stdio.h>
#include<stdlib.h>
#define N 10000

int main(){
  int n,i,j,count[N+1];
  unsigned short *in,*out;
  scanf("%d",&n);

  in=malloc(sizeof(short)*n+1);
  out=malloc(sizeof(short)*n+1);
  
  for(i=0;i<=N;i++){
    count[i]=0;
  }
  
  for(i=1;i<=n;i++){
    scanf("%d",&in[i]);
    count[in[i]]++;
  }
 
  for(i=1;i<=N;i++){
    count[i]=count[i]+count[i-1];
  }
 
  for(j=1;j<=n;j++){
    out[count[in[j]]]=in[j];
    count[in[j]]--;
  }
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",out[i]);
  }
  printf("\n");
  return 0;
}

