#include <stdio.h>
#define N 100

int main(){
int a[N],i,j,n,m=0,tmp,b;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&a[i]);
for(i=0;i<n;i++){
tmp = i;
for(j=i;j<n;j++){
if(a[j]<a[tmp]){
tmp=j;
}}
if(i!=tmp){
b=a[i];
a[i]=a[tmp];
a[tmp]=b; 
m++;

}
}
for(i=0;i<n;i++){
if(i==n-1)printf("%d\n",a[i]);
else printf("%d ",a[i]);
}
printf("%d\n",m);
return 0;
}
