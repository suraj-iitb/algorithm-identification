#include<stdio.h>

int main(){
  int n,s[100001],q,t,i,left,right,mid,ans = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",s + i);

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t);
    left = 0;
    right = n;
    while(left < right){
      mid = ( left + right ) / 2;
      if(s[mid] == t){
	ans++;
	break;
      }
      else if(s[mid] < t) left = mid + 1;
      else right = mid;
    }
  }

  printf("%d\n",ans);
  
  return 0;
}

