#include <stdio.h>
#define N 10000
#define M 500
int linearSearch(int,int[],int);
int main(){
  int a[N],b[M];
  int x,y,i,j,s=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<y;i++){
    if(linearSearch(b[i],a,x)==1){
      s++;
    }
  }
  printf("%d\n",s);
  return 0;
}

int linearSearch(int d,int a[],int x){
  int i=0;
  while(d!=a[i]||i==x){
    i++;
    if(i==x){
      return 0;
    }
  }
  return 1;
}
