#include <stdio.h>

int main(){
  int n,a[100],i,j,count=0,flag,x;
  scanf("%d",&n);
 
  for(i=0;i<n;i++) scanf("%d",&a[i]);
 for(j=0;j<n;j++){
   flag=0;   
for(i=n-1;i>j;i--){
     if(a[i]<a[i-1])
       {
	 x=a[i];
	 a[i]=a[i-1];
  a[i-1]=x;
  flag=1;
  count++;
}
}
   if(flag==0)break;

}
for(i=0;i<n-1;i++) printf("%d ",a[i]);
 printf("%d\n",a[n-1]);
printf("%d\n",count);
return 0;
}
