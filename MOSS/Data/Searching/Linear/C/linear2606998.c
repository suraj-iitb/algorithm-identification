#include<stdio.h>
#define MAX 10000
main(){
  int i,j,n,q,t[MAX],s[MAX];

  int count=0;
  
   scanf("%d",&n);
  
 for(i=0;i<n;i++)
    
   scanf("%d",&t[i]);
  
   scanf("%d",&q);
  
 for(i=0;i<q;i++)
    
   scanf("%d",&s[i]);
 
 for(i=0;i<q;i++)
    
    for(j=0;j<n;j++)
      
    if(t[j]==s[i]){
    
      count++;
   
       break;
      
  }
  
   printf("%d\n",count);
  
   return 0;

}
