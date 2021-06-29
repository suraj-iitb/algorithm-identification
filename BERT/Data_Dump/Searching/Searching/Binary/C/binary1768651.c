#include <stdio.h>

#define MAX 100000
int main(){

  int n,q,s[MAX],t,i,j,count=0;
  int l,m,r;

  //in
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);
  
  //in
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&t);
    l=0;
    r=n;
    
    while(l<r){
      m=(l+r)/2;
      if(s[m]==t){
	count++;
	break;
      }
      else if(s[m]<t){
	l=m+1;
      }else if(s[m]>t){
	r=m;
      }else{
	printf("exception %d",t);
      }
    }
  }
  
  //out
  printf("%d\n",count);
  
  return 0;
}
