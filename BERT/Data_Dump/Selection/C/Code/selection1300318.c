#include<stdio.h>
#define N 100

main(){

  int i,j,n,a[N],min,u=0,x;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }



  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){ 
	min=j;
      }    
    }
    if(i!=min){
    x=a[i];
    a[i]=a[min];
    a[min]=x;
    u++;
    }
  }


  for(i=0;i<n-1;i++){

      printf("%d ",a[i]);
 }
 printf("%d\n",a[n-1]);

 printf("%d\n",u);
 return 0;
}  
