#include <stdio.h>

int main(){
  int i,j,flag=1,count=0,len,array[100],num;

  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&array[i]);
  }
  i=0;
  while(flag){
      flag=0;
      for(j=len-1;j>=i+1;j--){
	if(array[j]<array[j-1]){
	  num=array[j];
	  array[j]=array[j-1];
	  array[j-1]=num;
	  count++;
	  flag=1;
	}
      }
      i++;
  }
  for(i=0;i<len;i++){
    printf("%d",array[i]);
    if(i==len-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}	

