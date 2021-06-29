#include <stdio.h>

int main()
{
  int n,q,s[100000],t[50000],cnt=0,i,j,key;
  int l,m,r;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++) scanf("%d",&t[j]);

  for(i=0;i<q;i++){
    l=0;
    r=n;
    while(l<r){
      key=t[i];
      m=(l+r)/2;
      if(s[m]==key){
	cnt++;
	break;
      }
      else if(key<s[m]) r=m;
      else l=m+1; 
    }
  }
  printf("%d\n",cnt);

  return 0;
}
