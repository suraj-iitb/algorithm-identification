#include <stdio.h>

int main(){
  int flg=1,i,n,array[100],box,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&array[i]);
 
  while( flg != 0){
    flg=0;
    for(i=n-1;i>0;i--){
      if(array[i] < array[i-1]){
	box = array[i];
	array[i] = array[i-1];
	array[i-1] = box;
	flg=1;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",array[i]);
    if( i == n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
