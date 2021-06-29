#include<stdio.h>

int main(){
  int sn,tn,count=0,i,j,t;
  int s[10000];
  scanf("%d",&sn);
  for(i=0;i<sn;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&tn);
  for(i=0;i<tn;i++){
    scanf("%d",&t);
    for(j=0;j<sn;j++){
      if(s[j]==t){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
