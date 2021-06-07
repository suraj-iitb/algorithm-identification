#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
  int i,j,s,t,n[10000],q[500],cnt=0;
  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&n[i]);
  }
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&q[i]);
    //printf("%d ",q[s]);
  }
  for(j=0;j<t;j++){
    for(i=0;i<s;i++)
      if (q[j]== n[i]) {cnt++;//printf("%d %d / %d %d\n",n[i],i,q[j],j);
	break;}
  }
  printf("%d\n",cnt);

  
  
}

