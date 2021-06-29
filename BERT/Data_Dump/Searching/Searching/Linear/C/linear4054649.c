#include<stdio.h>

int main(){
  int i,n,N[10000],q,cnt=0,j,p;
  //arry input
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&N[i]);
  //-------
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&p);
    for(j=0;j<n;j++)
      if(N[j]==p){
	cnt++;
	break;
      }
  }
  printf("%d\n",cnt);
  return 0;
}

