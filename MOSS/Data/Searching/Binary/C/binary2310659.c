#include <stdio.h>

int n,q;

int main(){
int s[100000],t[50000];
 int i,j,left, mid,right;
 int count =0;
  
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
       count++;
       break;
   }  
   else if(t[i] < s[mid]) right=mid;
   else left=mid+1;
 }
}
  
  printf("%d\n",count);

  return 0;
}
