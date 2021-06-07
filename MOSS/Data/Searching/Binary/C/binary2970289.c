#include<stdio.h>
#define LEN 100000
int main(){

  int i,mid,left,right,n,q,s[LEN],t[LEN],count=0;
  
  scanf("%d",&n);

  for(i=0;i < n ; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q ; i++){
    scanf("%d",&t[i]);
     left = 0;
     right = n;
    
    while(left < right){
      mid = (left + right) / 2;
      if (s[mid] == t[i]){
	count++;
      break;
      }
      else if(t[i]<s[mid]){
	  right = mid;
	}
      else if(t[i]>s[mid]){
	  left = mid + 1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
    

