#include <stdio.h>

int main(void)
{
 int i,n,s[100000],q,t[50000],left,right,mid,ans=0;

 scanf("%d",&n);

 for(i=0;i<n;i++){
  scanf("%d",&s[i]);
 }

 scanf("%d",&q);

 for(i=0;i<q;i++){
  scanf("%d",&t[i]);
 }

 for(i=0;i<q;i++){

  left=0;
  right=n;

  while(left<right){

   mid=(left+right)/2;
   if(s[mid]==t[i]){
    ans++;
    break;
   }else if(t[i]<s[mid]){
    right=mid;
   }else{
    left=mid+1;
   }
  }
 }

 printf("%d\n",ans);

 return 0;
}
