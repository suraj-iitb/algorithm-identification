#include <stdio.h>

#define MAX 10000
int main(){

  int n,q,s[MAX],t[MAX],i,j,count=0;

  //in
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);
  
  //in
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
  //Search
  for(i=0;i<q;i++){
    j=0;
    s[n]=t[i];
    while(s[j]!=t[i]){
      j++;
    }
    if(j!=n) count++;
  }
  
  //out
  printf("%d\n",count);
  
  return 0;
}
