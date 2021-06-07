#include <stdio.h>
#define N 100000
#define Q 50000
main(){
  int n,q,s[N],t[Q];
  int i,j,count=0;
  int left,right,mid;
 
  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&s[i]);
  
  scanf("%d",&q);
  for(i=0;i<q; i++)
    scanf("%d",&t[i]);
  

  for(i=0; i<q; i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(t[i]==s[mid]){
	count++;
	break;
      }
      if(t[i]>s[mid])
	left=mid+1;
      else if(t[i]<s[mid])
	right=mid;
    }
  }
  
  
  
  printf("%d\n",count);
  return 0;
}
