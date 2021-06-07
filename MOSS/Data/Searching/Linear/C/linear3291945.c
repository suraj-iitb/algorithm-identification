#include<stdio.h>

#define M 10000

int main(){
  int n,s[M],q,t[M],c=0;
  int i,j;

 
  scanf("%d",&n);
  for(i=0 ; i<n ; i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)scanf("%d",&t[i]);


  
  for(j=0 ; j<q ; j++){
  i = 0;
  s[n] = t[j];
  while(s[i] != t[j]) i++;
  if(i != n) c++;
  }
  
  printf("%d\n",c);

  return 0;
}

  
    

