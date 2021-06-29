#include<stdio.h>
#include<stdlib.h>

int main(){
  int swcut=0,flag=1;
  int n,*a,i,stock;
  
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  while(flag){
    flag=0;
    for(i=n-1;0<i;i--){
      if(a[i]<a[i-1]){
	stock=a[i];
	a[i]=a[i-1];
	a[i-1]=stock;
	swcut++;
	flag=1;
      }
    }
 
  }

  for(i=0;i<n;i++){
  printf("%d",a[i]);
  if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",swcut);
  
  return 0;
}

