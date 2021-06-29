#include <stdio.h>
#include <stdlib.h>

int n,count=0;
int *sort(int *);

int main(){

  int i,*a,*b;
  
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  b=(int *)malloc(n*sizeof(int));
  //printf("aaa\n");

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  //printf("bbb\n");
  b=sort(a);

  for(i=0;i<n;i++){
    if(i!=n-1)printf("%d ",b[i]);
    else {
      printf("%d\n",b[i]);
      printf("%d\n",count);
    }
  }

  return 0;
}
int *sort(int *a){
  int c,i,flag=1;
  
  while(flag!=0){
    flag=0;
    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	c=a[i];//a[i]を記録しておく
	a[i]=a[i-1];
	a[i-1]=c;
	count++;
	flag=1;
      }  
    }
  }
  return a;
}


