#include<stdio.h>

main(void){
  
  int s[10000],n,t[500],q,i,count=0,j,temp;
  int left,mid,right,value;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
    
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(s[j]<s[j-1]){
	temp=s[j];
	s[j]=s[j-1];
	s[j-1]=temp;
      }
    }
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
