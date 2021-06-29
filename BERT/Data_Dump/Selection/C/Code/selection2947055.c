#include<stdio.h>
#define N 100

int main(){
  int a,b[N],c,i,j,count,minj;
  count=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<a;i++){
    minj=i;
    for(j=i;j<a;j++){
      if(b[j]<b[minj]){
	minj=j;
      }
    }
      if(i!=minj){
	c=b[i];
	b[i]=b[minj];
	b[minj]=c;
	count++;
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

