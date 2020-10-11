#include<stdio.h>

int main(){

  int a[100],t,i,j,length,flag,count=0;
  
  scanf("%d",&length);
  
  for(i=0;i<length;i++)
    scanf("%d",&a[i]);
  
  flag = 1;
  while (flag){
    flag = 0;

    for(j=length-1;j>0;j--)
      {
	if(a[j]<a[j-1]){
	  t = a[j];
	  a[j] = a[j-1];
	  a[j-1]=t;
	  flag = 1;
	  count++;
	    }
      }
  }
  for(j=0;j<length;j++){
    
    printf("%d",a[j]);
    if(j != length-1)
      printf(" ");
  }
  printf("\n");
    
  printf("%d\n",count);

  return 0;
}

