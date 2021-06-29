#include<stdio.h>
int main(){
  int s[10000],t[500],n,q,i,j,count=0,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
   scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
    k=t[i];
      for(j=0;j<n;j++){
	if(k==s[j]){
	  count++;
	  break;
	}
      }
  }
  printf("%d\n",count);
  return 0;
}
		    
	  

