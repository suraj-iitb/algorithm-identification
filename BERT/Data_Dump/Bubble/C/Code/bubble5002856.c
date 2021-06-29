#include<stdio.h>
int main(){
  int x,y[105],flag=1,count=0;
  scanf("%d",&x);
  for (int i=0;i<x;i++){
    scanf("%d",&y[i]);
  }
  int i=0;
  while(i<x-1&&flag==1){
    flag=0;
    for (int j=0;j<x-i-1;j++){
      if(y[j]>y[j+1]){
        int temp= y[j];
        y[j]=y[j+1];
        y[j+1]=temp;
        count++;
        flag=1;
      }
    }
    i++;
  }
  for (int i=0;i<x;i++){
    if(i!=(x-1)){
        printf("%d ",y[i]);
    }else{
        printf("%d\n",y[i]);
    }
  }
  printf("%d\n",count);
}
