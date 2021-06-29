#include <stdio.h>

int main(){
  int n,a[100],i,j,count=0,x,min;
  scanf("%d",&n);
 
  for(i=0;i<n;i++) scanf("%d",&a[i]);
 for(j=0;j<n;j++){
   min=j;   
for(i=j;i<n;i++){
     if(a[i]<a[min])
       min=i;
	
}   
 if(min!=j){
x=a[j];
	 a[j]=a[min];
  a[min]=x;
count++;
 }
}
for(i=0;i<n-1;i++) printf("%d ",a[i]);
 printf("%d\n",a[n-1]);
printf("%d\n",count);
return 0;
}
