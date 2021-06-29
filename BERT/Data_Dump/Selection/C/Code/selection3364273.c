#include<stdio.h>
int main(){

  int i,j,datanum,minj,flag,cnt=0,temp;
  int a[101];
  scanf("%d",&datanum);
  for(i=0;i<datanum;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<datanum;i++){
    minj = i;
    flag = 0;
    for(j=i;j<datanum;j++){
      if(a[j] < a[minj]){
	minj = j;
	flag = 1;
      }
    }
    if(flag == 1){
      temp = a[minj];
      a[minj] = a[i];
      a[i] = temp;
      cnt++;
    }
  }
  
  for(i=0;i<datanum;i++){
    if(i == datanum -1){
      printf("%d\n",a[i]);
      break;
    }
    printf("%d ",a[i]);
  }
  
  printf("%d\n",cnt);
  return 0;
}


