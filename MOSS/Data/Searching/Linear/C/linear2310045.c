#include <stdio.h>
int main(){
  int i,j,c=0,n=0,q=0,s[10000],t[500];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&t[j]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(s[j]==t[i]){
	c++;
	break;
      }
      else continue;
    }
  }
 
  printf("%d\n",c);
  return 0;
}
