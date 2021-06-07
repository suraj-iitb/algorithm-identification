#include <stdio.h>

int main(){
  int n,q,i=0,j=0,c=0;
  int s[100000],t[500];

  while(1){
    scanf("%d",&n);
    if(n<=10000){
      while(i<n){
	scanf("%d",&s[i]);
	if(0<=s[i]&&s[i]<=1000000000) i++;
      }
      break;
    }
  }

  i=0;
  while(1){
    scanf("%d",&q);
    if(q<=500){
      while(i<q){
	scanf("%d",&t[i]);
	if(0<=t[i]&&t[i]<=1000000000) i++;
      }
      break;
    }
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);

  return 0;
}

