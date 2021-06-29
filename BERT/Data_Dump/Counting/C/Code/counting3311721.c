#include <stdio.h>
#include <stdlib.h>

#define A 2000001
#define B 10000

int main(){
  unsigned short *m,*n;
  int S[B+1],q,i,j;

  scanf("%d",&q);

  m = malloc(sizeof(short)*q+1);
  n = malloc(sizeof(short)*q+1);

  for(i=0;i<=B;i++){
    S[i]=0;
  }

  for(i=0;i<q;i++){
    scanf("%hu",&m[i+1]);
    S[ m[i+1] ]++;
  }

  for(i=1;i<=B;i++){
    S[i]= S[i]+S[i-1];
  }

  for(j=1;j<=q;j++){
    n[ S[ m[j] ] ] = m[j];
    S[ m[j] ]--;
  }

  for(i=1;i<=q;i++){
    if(i>1) printf(" ");
    printf("%d",n[i]);
  }
  printf("\n");
  return 0;
}

