#include<stdio.h>

main(void){
  
  int s[100000],n,t[50000],q,i,count=0,j,temp;
  int left,mid,right,value;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
    
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
 
    
  
  for(i=0;i<q;i++){
    right=n;
    left=0;
    value=t[i];
   
    while(left<=right){
      mid=(left+right)/2;

      if(s[mid]==value){
	count=count+1;
	break;
      }

      else if(s[mid]<value)left=mid+1;

      else right=mid-1;

    }
  }
  
  printf("%d\n",count);
  return 0;
}
