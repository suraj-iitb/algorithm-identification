#include<stdio.h>

int main(){
  int n,q,i,j,c=0,t,start;
  
  scanf("%d",&n);
  int s[n];
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    start=0;
    for(j=start;j<n;j++){
      if(s[j]==t){c++;start=j;break;}
    }
  }
  printf("%d\n",c);
  return 0;
}

