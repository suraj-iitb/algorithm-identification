#include<stdio.h>

int main(){
  int s[10000],t[500];
  int n,q,i,j,num=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&t[i]);

  i=0;
  j=0;
  while(j<q){
    s[n] = t[j];
    while(t[j] != s[i])
      i++;
    if(i != n)
      num++;
    i =0;
    j++;
  }

  printf("%d\n",num);

  return 0;
}
