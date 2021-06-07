#include<stdio.h>
#define MAXS 100000
int main(){
  int n,q,i,s[MAXS],t,c=0;
  int left,right,mid;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    left=0;
    right=n;
    while (left<right){
      mid=(left+right)/2;
      if(s[mid]==t){
	c++;
	break;
      }else if(t<s[mid])
	right=mid;
      else left=mid+1;
    }
  }
  printf("%d\n",c);
  return 0;
}

