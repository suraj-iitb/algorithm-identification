#include<stdio.h>
int main(){
int i=0,j=0,a[1000],p=0,key=0,n=0;
scanf("%d",&p);
for(i=0;i<p;i++){
scanf("%d",&a[i]);
}
for(n=0;n<p-1;n++){
printf("%d ",a[n]);
}
printf("%d\n",a[n]);
for(i=1;i<p;i++){
key=a[i];
j=i-1;
while(j>=0 && a[j]>key){
a[j+1]=a[j];
j--;
a[j+1]=key;
}
for(n=0;n<p-1;n++){
printf("%d ",a[n]);
}
printf("%d\n",a[n]);
}
return 0;
}
