#include<stdio.h>

#define M 100000

int main(){
  int n,s[M],q,t[M],c=0;
  int left,right,mid;
  int i;

 
  scanf("%d",&n);
  for(i=0 ; i<n ; i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)scanf("%d",&t[i]);

  for(i=0 ; i<q ; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(s[mid] == t[i]){
	c++;
	break;
      }
      else if(t[i] < s[mid]) right = mid;
      else left = mid + 1;
    }

  }
  
  printf("%d\n",c);

  return 0;
}

