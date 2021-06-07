#include <stdio.h>

int main(){
  int n,q,i=0,c=0,m,r,l,a;
  int s[100000];

 
    scanf("%d",&n);
    while(i<n){
      scanf("%d",&s[i]);
      if(0<=s[i]&&s[i]<=1000000000) i++;
    }

    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&a);
      l=0;
      r=n;
      while(l<r){
	m=(l+r)/2;
	if(a==s[m]){
	  c++;
	  break;
	}
	else if(a<s[m]){
	  r=m;
	}
	else if(a>s[m]){
	  l=m+1;
	}
      }
    }

    printf("%d\n",c);

    return 0;
}

