#include<stdio.h>
int main(){
  int b,c,i,j,k,d=0;
  scanf("%d",&b);
  int a[b];
  for(k=0;k<b;k++){
    scanf("%d",&a[k]);
  }
  for(i=0;i<b-1;i++){
    for(j=b-1;j>i;j--){
      if(a[j-1]>a[j]){
	c=a[j];
	a[j]=a[j-1];
	a[j-1]=c;
	d=d+1;
      }
    }
  }
    for(k=0;k<b-1;k++){
      printf("%d ",a[k]);
  }
    printf("%d\n",a[b-1]);
    printf("%d\n",d);
    return 0;
  }

