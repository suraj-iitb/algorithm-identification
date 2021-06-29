#include<stdio.h>
int main(){

  int i,j,data,minj,flag,count=0,temp;
  int a[101];
  scanf("%d",&data);
  for(i=0;i<data;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<data;i++){
    minj = i;
    flag = 0;
    for(j=i;j<data;j++){
      if(a[j] < a[minj]){
	minj = j;
	flag = 1;
      }
    }
    if(flag == 1){
      temp = a[minj];
      a[minj] = a[i];
      a[i] = temp;
      count++;
    }
  }

  for(i=0;i<data;i++){
    if(i == data -1){
      printf("%d\n",a[i]);
      break;
    }
    printf("%d ",a[i]);
  }

  printf("%d\n",count);
  return 0;
}

