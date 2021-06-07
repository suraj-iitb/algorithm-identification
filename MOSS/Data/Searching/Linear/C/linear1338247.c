#include<stdio.h>
main(){
  int i,j,m,n,sum=0,S[10001],T[500];
  scanf("%d",&m);
  for(i=0;i<m;i++)scanf("%d",&S[i]);
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&T[i]);
  
  for(i=0;i<n;i++){
    S[m]=T[i];
    j = 0;
    while(S[j]!=T[i]){
      j++;
      if(j==m)break;
    }
    if(j!=m)sum++;
  }
  
  printf("%d\n",sum);
  return 0;
} 
