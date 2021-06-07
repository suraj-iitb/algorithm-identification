#include <stdio.h>
#include <stdlib.h>
int n, *s;

int linearSearch(int x){
  int i=0;
  s[n]=x;
  while(s[i]!=x){
    i++;
  }
  if(i==n){
    return 0;
  }else{
    return 1;
  }
}
int main(void){

  int  i, q, *t, count=0;

  scanf("%d", &n);
  s=(int *)malloc((n+1)*sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  t=(int *)malloc(q*sizeof(int));
  for(i=0; i<q; i++){
    scanf("%d", &t[i]);
  }

  for(i=0; i<q; i++){
    if(linearSearch(t[i])==1){
      count++;
    }else if(linearSearch(t[i])==0){
      continue;
    }
  }

  printf("%d\n", count);

  return 0;
}

