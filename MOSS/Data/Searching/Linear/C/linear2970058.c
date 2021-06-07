#include<stdio.h>
#define N 10000

int main(){
  int n,i,j,t,q,s[N],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    for(j=0;j<n;j++){
      if(s[j]==t){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

