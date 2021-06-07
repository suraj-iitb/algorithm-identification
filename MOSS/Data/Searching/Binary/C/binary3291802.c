#include<stdio.h>                                                                                                      
                                                                                                                       
int listsearch(int *s,int t,int m,int n){                                                                              
  int j=0,count=0,left=0,right=n,mid;                                                                                  
                                                                                                                       
                                                                                                                       
    mid= (left+right)/2;                                                                                               
    while(left<right){                                                                                                 
      mid= (left+right)/2;                                                                                             
      if(s[mid]==t)return 1;                                                                                           
      else if(s[mid]<t)left=mid+1;                                                                                     
      else right=mid;                                                                                                  
    }                                                                                                                  
  return 0;                                                                                                            
}                                                                                                                      
                                                                                                                       
int main(){                                                                                                            
                                                                                                                       
  int s[100000],t,i,n,m,a=0;                                                                                           
                                                                                                                       
  scanf("%d",&n);                                                                                                      
                                                                                                                       
  for(i=0;i<n;i++){                                                                                                    
    scanf("%d",&s[i]);                                                                                                 
  }                                                                                                                    
                                                                                                                       
  scanf("%d",&m);                                                                                                      
  for(i=0;i<m;i++){                                                                                                    
    scanf("%d",&t);                                                                                                    
    a+=listsearch(s,t,m,n);                                                                                            
  }                                                                                                                    
  printf("%d\n",a);                                                                                                    
  return 0;                                                                                                            
  }                                                                                                                    
                                                                                                                       
                                                                                                                       
                                                                                                                       
                                                                                                                       
                                                                                                                       
