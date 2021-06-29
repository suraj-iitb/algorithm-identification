#include<stdio.h>
#include<stdlib.h>

int main(){

  int str;
 
  int i,j,key,k;

  scanf("%d",&str);
  if(str<1&&str>100){
    printf("Presentation Error\n");
    exit(1);
  }
 int inp[str];
  

  for(i=0;i<str;i++){
    scanf("%d",&inp[i]);

   
    if(inp[i]<0&&inp[i]>1000){
      printf("Presentation Error\n");
      exit(1);}
  }

  for(i=0;i<str;i++){
    printf("%d",inp[i]);
    if(i<str-1)printf(" ");
    
  }
  printf("\n");


  
  for(i=1;i<str;i++){
    key = inp[i];
    j = i - 1;
    while(j >= 0 && inp[j]>key){
      inp[j+1]=inp[j];
      j--;
    }
      inp[j+1]=key; 
      for(k=0;k<str;k++){
	printf("%d",inp[k]);
	if(k<str-1){
	  printf(" ");}
      }
      printf("\n");

    
  }
    
  return 0;
}

