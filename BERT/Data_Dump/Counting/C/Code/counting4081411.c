#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int main(){
  unsigned short *n1,*n2;
  int ntime,i,array[MAX+1];

  scanf("%d",&ntime);

  n1=(short*)malloc((ntime+1)*sizeof(short));
  n2=(short*)malloc((ntime+1)*sizeof(short));

  for(i=1;i<=ntime;i++) scanf("%hu",&n1[i]);

  for(i=0;i<=MAX;i++) array[i]=0;
  

  for(i=0;i<ntime;i++) array[n1[i+1]]++;
  

  for(i=1;i<MAX;i++) array[i]=array[i]+array[i-1];
  

  for(i=ntime;i>0;i--){
    n2[array[n1[i]]]=n1[i];
    array[n1[i]]--;
  }

  for(i=1;i<ntime;i++) printf("%d ",n2[i]);
  printf("%d\n",n2[i]);

  free(n1);
  free(n2);

  return 0;
}
