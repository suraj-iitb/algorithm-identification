#include<stdio.h>
#define N 10000
#define M 500
main()
{
  int s[N],t[M],i,q,n,l=0,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    
    scanf("%d",&s[i]);
    
  }
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    
    scanf("%d",&t[i]);
    for(j=0;j<n;j++){
      if(s[j]==t[i]){
	l++;
	break;
      }
  }
  }
 
  printf("%d\n",l);
  return 0;
}
