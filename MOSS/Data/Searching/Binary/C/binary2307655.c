#include <stdio.h>

int main(){
  
  int s[100000];
  int t[50000];
  int n,q,i,count=0;
  int left,right,mid;

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
      if(t[i]==s[mid]) {
	count++;
	break;
      }
      if(t[i]>s[mid]){
	left=mid+1;
      }
      else if(t[i]<s[mid]){
	right=mid;
      }
    }
  }

  printf("%d\n",count);

  return 0;
  
}
