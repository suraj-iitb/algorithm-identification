#include<stdio.h>
int main(){
  int n,q,i,ans=0,j,flag=0;
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
     j=0;
     flag=0;
     while(j<n){
       if(t[i]==s[j]){
	 ans=ans+1;
	 flag=1;
       }
       if(flag==1){j=n;}
       j++;
     }
     
   }
   
     printf("%d\n",ans);
   return 0;
}

