#include<stdio.h>

int main(){
  int i, j=0, n, q, S[10000], T[10000], count=0, key;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    key=T[i];
    S[n]=key;
    while(S[j]!=key){
	j++;
      }
    if(j!=n)count++;
    j=0;
  }

  printf("%d\n",count);

  return 0;
}
