#include<stdio.h>
int main(){
int a[101],b,c=0,i,j,d;
scanf("%d\n",&b);
for(i=0;i<b;i++){
scanf("%d",&a[i]);
}
for(i=0;i<b;i++){
for(j=b-1;j>i;j--){
if(a[j-1]>a[j]){
c++;
d=a[j];
a[j]=a[j-1];
a[j-1]=d;
}
}
}
for(i=0;i<b;i++){
if(i==b-1){
printf("%d",a[i]);
}
else{
printf("%d ",a[i]);
}
}
printf("\n");
printf("%d\n",c);
return 0;
}
