#include <stdio.h>

int main(){

  int select[100];
  int n,i,j,minj,count=0,c;

  scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%d",&select[i]);
  }

  for(i=0; i < n; i++){
    minj=i;
    for(j=i; j < n; j++){
      if(select[j] < select[minj]){
	minj=j;
      }
    }
      c=select[minj];
      select[minj]=select[i];
      select[i]=c;

      if(i!=minj)
	count++;
    }
for(i=0; i < n; i++){
  printf("%d",select[i]);
  if(i==n-1)
    printf("\n");
  else 
    printf(" ");
 }

 printf("%d\n",count);


return 0;

}
