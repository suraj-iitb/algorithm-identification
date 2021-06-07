#include<stdio.h>
#define N 1000001

int main(){
  int n,s[N],q,t[N],l,r,m,res=0,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0;i<q;i++){
    l=0;
    r=n;
    m=(r+l)/2;
    while(r-l>1){
      
      if(s[m]<=t[i]){
	 
	l=m;
	m=(l+r)/2;
	
      }
      
      else if(s[m]>t[i]){
	
	r=m;
	m=(l+r)/2;
	
      }
    }
    
    if(s[l]==t[i]){
      res++;
    }
    
  }
  printf("%d\n",res);
  return 0;
}

