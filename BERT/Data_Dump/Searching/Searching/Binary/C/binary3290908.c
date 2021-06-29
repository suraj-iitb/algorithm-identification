#include<stdio.h>
int main(){
  int n,q,i,j,c=0,r,l,m;
  int s[100000],t[50000];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  for(i=0;i<q;i++){

    l=0;
    r=n;
    
    while(l<r){
      m=(l+r)/2;
      
      if(t[i]==s[m]){
	c++;
	break;
      }

      else if(t[i]<s[m]) r=m;

      else if(t[i]>s[m]) l=m+1;

      else l=m+1;
    }
    
  }

  printf("%d\n",c);

  return 0;
}

