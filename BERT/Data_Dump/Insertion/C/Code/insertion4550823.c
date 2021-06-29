#include<stdio.h>
int main(){
  int a,b[100],i,j,n,key;
  scanf("%d",&a);
  if(1<=a && a<=100){
    for(i=0;i<a;i++){
      scanf("%d",&b[i]);
    }

    for(i=0;i<a;i++){
      key=b[i];
      j=i-1;
      while(j>=0 && b[j]>key){
	b[j+1]=b[j];
	j-=1;
	b[j+1]=key;
      }
     for(n=0;n<a-1;n++){
	printf("%d ",b[n]);
      }
     printf("%d\n",b[n]);
    }
  }
  return 0;
}

