#include<stdio.h>

int main(){
  int i,j,n,m,P[10000],Q[500],c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&P[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&Q[i]);
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(P[j]==Q[i]){
	c++;
	break;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}

