#include<stdio.h>
int main(){
  int n,q,i,ans=0,j,flag=0,m,l,r;
  scanf("%d",&n);
  int s[n];
  for(i=0;i<n;i++){
  scanf("%d",&s[i]);

  }
  scanf("%d",&q);
  int t[q];
   for(i=0;i<q;i++){
  scanf("%d",&t[i]);
  }
  
 
   for(i=0;i<q;i++){
   l=0;
   r=n;
    m=(l+r)/2;
     while(l<r){
      
       if(s[m]>t[i]){
	 r=m;
	 m=(l+r)/2;
       }
       else if(s[m]==t[i]){
	 ans+=1;
	 break;
       }
       else{
	 l=m+1;
	 m=(l+r)/2;
       }
       
     }
   }

   printf("%d\n",ans);

  return 0;
}

