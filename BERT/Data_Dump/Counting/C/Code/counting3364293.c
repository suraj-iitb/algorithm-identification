#include<stdio.h>
#include<stdlib.h>
#define MAXDATA 10001
int main(){
  int i,datanum,temp;
  int *a,*b;
  int c[MAXDATA];//a ni dainyu
  scanf("%d",&datanum);
  a = (int *)malloc(sizeof(int) * (datanum + 1));
  b = (int *)malloc(sizeof(int) * (datanum + 1)); //sizeがおおきすぎて、mallocじゃないとエラー吐く
  
  for(i=0;i<MAXDATA;i++){
    c[i] = 0;
  }
  for(i=0;i<datanum;i++){
    scanf("%d",&a[i + 1]);
    c[a[i + 1]]++; 
  }
  for(i=1;i<=MAXDATA;i++){
    c[i] = c[i] + c[i-1];
  }
  
  for(i=datanum;i>=1;i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  for(i=1;i<=datanum;i++){
    if(i != 1)printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  return 0;
}


