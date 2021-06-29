#include<stdio.h>
#define N 10000
#define q 500
int linearSearch(int *,int,int);


int main(){
  int a[N],x,y,i,j,count=0,r;

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
   scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&r);
    j=linearSearch(a,x,r);
    if(j==1) count++;
  }

  printf("%d\n",count);
  
  return 0;
}


int linearSearch(int *a,int x,int key){
  int i=0;
  a[x] = key;

  while(key!=a[i]){
    i++;
  }
  if(i==x) return 0;
  return 1;
  
}
