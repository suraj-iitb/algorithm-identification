#include<stdio.h>

main(){

  int n,q,i,j,c = 0;
  int s[10000],t[500];

  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
  }
  
  for(j = 0;j < q;j++){
    for(i = 0;i < n;i++){
      if(s[i]==t[j]){
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}
