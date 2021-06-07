#include <stdio.h>
#include <stdlib.h>
  
int linearSearch(int *, int, int);
  
main(){
  int n,q,i,findN=0;
  int *sAry, *tAry;
  
  scanf("%d", &n);
  sAry = (int *)malloc((n+1)*sizeof(int)); //????????¨???+1
  for(i=0; i<n; i++) scanf("%d", sAry+i);
  scanf("%d", &q);
  tAry = (int *)malloc(q*sizeof(int));
  for(i=0; i<q; i++) scanf("%d", tAry+i);
  
  for(i=0; i<q; i++) findN+=linearSearch(sAry, n, tAry[i]);
  
  printf("%d\n", findN);
  
  return 0;
}
  
int linearSearch(int *ary, int n, int a){
  int i=0;
  ary[n]=a;
  while(ary[i]!=a) i++;
  if(i==n) return 0;
  return 1;
}
