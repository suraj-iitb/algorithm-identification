#include<stdio.h>
int main(){
  int i,n,q,s[100000],t,c=0,right,left,mid;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(t==s[mid]){
        c++;
        break;
      }
      if(t>s[mid])left=mid+1;
      else if(t<s[mid])right=mid;
    }
  }
  printf("%d\n",c);
  return 0;
}
