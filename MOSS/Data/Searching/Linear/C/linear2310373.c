#include<stdio.h>

int serch(int a[],int b,int key){
  int c=0;
  a[b]=key;
  while(a[c]!=key) c++;
  if(c==b) return 0;
  else return 1;
}
  

int main(){
  int i,b,d,a[10001],sum=0,key;
    scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  for(i=0;i<d;i++){
    scanf("%d",&key);
    if(serch(a,b,key)) sum++;
  }

  printf("%d\n",sum);

    return 0;
}
