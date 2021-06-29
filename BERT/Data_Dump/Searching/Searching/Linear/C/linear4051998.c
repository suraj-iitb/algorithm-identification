#include<stdio.h>

int main(){

  int i,a=0,j,l,c=0,n,num[10000],q,qnum[500];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&qnum[j]);
  }

  
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(num[i] == qnum[j]) {
	c++;
	break;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}
