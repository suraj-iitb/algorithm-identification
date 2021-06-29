#include<stdio.h>
#define N 100000

int main(){
  int n,i,s[N],q,t,left,right,mid,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(s[mid]==t){
	count++;
	break;
      }
      else if(t<s[mid]){
	right=mid;
      }else{
	left=mid+1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

