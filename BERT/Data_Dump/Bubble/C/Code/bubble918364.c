#include<stdio.h>
#define N 100

int main(){
int a[N],i,j,n,m=0,tmp;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&a[i]);
for(i=0;i<n;i++){
for(j=n-1;j>i;j--){
if(a[j]<a[j-1]){
tmp=a[j];
a[j]=a[j-1];
a[j-1]=tmp;
m++;
}
}
}
for(i=0;i<n;i++){
if(i==n-1)printf("%d\n",a[i]);
else printf("%d ",a[i]);
}
printf("%d\n",m);
return 0;
}
