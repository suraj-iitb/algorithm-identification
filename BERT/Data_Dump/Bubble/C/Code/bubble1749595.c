#include<stdio.h>

int main(){

  int i,j,temp,count=0,flag=1,n,x[100];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
 
    scanf("%d",&x[i]);

  }

  while(flag == 1){
  
    flag = 0;
  
    for(j = n-1 ; j > 0   ; j--){

      if(x[j] < x[j-1]){
   
	temp = x[j-1];
        x[j-1] = x[j];
	x[j] = temp;
        flag = 1;
        count++;
      }

    }

  }


  for(i = 0 ; i < n ; i++){
 

    printf("%d",x[i]);
    if(i ==  n-1){
      break;
    }
    printf(" ");

  }
  
  printf("\n");

  printf("%d\n",count);
  
  return 0;
}
