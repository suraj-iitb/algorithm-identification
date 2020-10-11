#include<stdio.h>
#define N 100

int main(){
  int a,b[N],c,count,flag,i;
  count=0;
  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  flag=1;
  while(flag){
    flag=0;
    for(i=a-1;i>0;i--){
      if(b[i]<b[i-1]){
	c=b[i];
	b[i]=b[i-1];
	b[i-1]=c;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<a;i++){
    printf("%d",b[i]);
    if(i+1==a)break;
    printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

