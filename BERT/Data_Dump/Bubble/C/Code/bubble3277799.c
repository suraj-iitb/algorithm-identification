#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b);

int main(){
  int *a,i,j,x,f,temp,cnt=0;
  scanf("%d",&x);
  a=malloc(sizeof(int)*(x+1));
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  //バブルソート
  for(i=0;i<x-1;i++){
    for(j=x-1;j>i;j--){
      if(a[j]<a[j-1]){
        swap(&a[j],&a[j-1]);
        cnt++;
      }
    }
  }
  //表示
  for(i=0;i<x-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[x-1]);
  printf("%d\n",cnt);
  return 0;
}
void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

