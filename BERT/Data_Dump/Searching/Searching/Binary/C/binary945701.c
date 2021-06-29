#include<stdio.h>
#define N 100000
#define M 50000
main()
{
  int s[N],t[M],i,q,n,l=0,j,left,right,mid;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    
    scanf("%d",&s[i]);
    
  }
 
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    
    scanf("%d",&t[i]);
    
  }
  
  for(j=0;j<q;j++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(t[j]==s[mid]){
	l++;
	break;
      }
      if (t[j]>s[mid]){
	
	left=mid +1;
      }
      else if(t[j]<s[mid]){
	
	right=mid;
      }
    }
    
  }
  
  printf("%d\n",l);
  return 0;
}
