#include<stdio.h>

int main(){
  int n[10000],q[500];
  int s,t,i,j,count=0;

  scanf("%d",&s);
  for(i=0;i<s;i++) scanf("%d",&n[i]);
  scanf("%d",&t);
  for(i=0;i<t;i++) scanf("%d",&q[i]);

  for(i=0;i<t;i++){
    for(j=0;j<s;j++){
      if(q[i]==n[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

