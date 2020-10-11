#include<stdio.h>
#define NUM 100


int main(){
  int i,n,count,flag,hoji;
  int a[NUM];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  flag=1;
  while(flag>0){
    flag=0;
    for(i=n-1;i>=1;i--){
      if(a[i]<a[i-1]){
	hoji=a[i];
	a[i]=a[i-1];
	a[i-1]=hoji;
	count++;
	flag=1;
      }
    }
  }


  for(i=0;i<n;i++){
    if(i!=n && i!=0){
      printf(" ");
    }
    printf("%d",a[i]);
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}


