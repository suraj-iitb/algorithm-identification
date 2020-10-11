#include<stdio.h>

int main(){
  int a[100];
  int datanum,i,temp,j,datachange=0;
  scanf("%d",&datanum);
  for(i=0;i<datanum;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<datanum;i++)
    for(j=0;j<datanum-1;j++){
      if(a[j] > a[j+1]){
	datachange++;
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
      }
    }
  for(i=0;i<datanum;i++){
    if(i == datanum-1){
      printf("%d\n",a[i]);
      break;
    }
    printf("%d ",a[i]);
  }
  printf("%d\n",datachange);
  return 0;

}

