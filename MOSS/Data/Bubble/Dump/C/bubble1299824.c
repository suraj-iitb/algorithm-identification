#include<stdio.h>
int main(){
  int i,j=0,x,count=0,g,n[100];
  scanf("%d",&g);
  for(i=0;i<g;i++)scanf("%d",&n[i]);
  for(j=0;j<g-1;j++){
    for(i=g-1;i>j;i--){
      if(n[i]<n[i-1]){
	x = n[i-1];
	n[i-1] = n[i];
	n[i] = x;
	count++;
      }}
  }
  for(i=0;i<g;i++){
        printf("%d",n[i]);
        if(i<g-1)printf(" ");
}
  printf("\n%d\n",count);
  return 0;
}
