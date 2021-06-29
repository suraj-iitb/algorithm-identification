#include<stdio.h>
main(){
  int i,j,g,min,h=0,count=0,x,n[100];
  scanf("%d",&g);
  for(i=0;i<g;i++)scanf("%d",&n[i]);
  for(i=0;i<g;i++){
    min = i;
    h=0;
    for(j=i;j<g;j++){
      if(n[j] < n[min]){
	min = j;
        h++;}
    }
    if(h>0){
	x = n[i];
	n[i] = n[min];
	n[min]= x;
	count++;
    }}

  for(i=0;i<g;i++){
    printf("%d",n[i]);
    if(i<g-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
