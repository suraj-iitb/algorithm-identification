#include <stdio.h>

int main(){
  int r ,l, n,q,s[100000],t[50000],i,j,count=0,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    l=0;
    r=n;
    while(l<r){
      mid = (l+r)/2;
      if(s[mid]==t[i]){
	count++;
	break;
      }
      else if(t[i]<s[mid]){
	r=mid;
      }
      else{
	l=mid+1;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

