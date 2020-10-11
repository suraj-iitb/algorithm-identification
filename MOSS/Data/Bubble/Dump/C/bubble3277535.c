#include<stdio.h>
#define A 100

int main(){
  int tmp,flag=1,i,a[A],n,sw=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  while(flag==1){
    flag=0;

    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	tmp=a[i];
	a[i]=a[i-1];
	a[i-1]=tmp;
	flag=1;
	sw++;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],sw);
  
  
  return 0;
}

