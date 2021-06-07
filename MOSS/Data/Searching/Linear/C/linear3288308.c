#include<stdio.h>


int main (){

  int S[10000],T[500];
  int s,t,i,j=0,k=0;
  
  

  scanf("%d",&s);

  for(i=0;i<s;i++)
    scanf("%d",&S[i]);

  scanf("%d",&t);

  for(i=0;i<t;i++)
    scanf("%d",&T[i]);

  for(i=0;i<t;i++){
    k = 0;
    S[s] = T[i];
    while(S[k]!=T[i])
      k++;
    if(k == s)continue;
    else j++;
  }

  printf("%d\n",j);
  return 0;
}
    

