#include<stdio.h>
#define MAX 1000000
int main(){
  int i,j=1,n,q,cou=0;
    int S[MAX],key;

  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
    
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&key);
    for(j=0,S[n]=key;S[j]!=key;j++);
    if(j!=n)cou++;

  }
  
  /* for(i=0;i<q;i++){
     for(j=0;j<n;j++){
     if(T[i]==S[j])cou++;
     }
     }
  */
  printf("%d\n",cou);

  return 0;
}
