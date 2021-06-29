#include <stdio.h>
int main(){
  int n,x[100],i,j,flag=0,tmp,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  flag=1; 
    while(flag){
      flag=0;
      for(j=1;j<=n-1;j++){
	if(x[j]<x[j-1]){
	    tmp=x[j];
	    x[j]=x[j-1];
	    x[j-1]=tmp;
	    cnt++;
	    flag=1;
	}
      }
    }
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%d",x[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

  

