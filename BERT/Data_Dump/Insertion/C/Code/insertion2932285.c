#include<stdio.h>
int main(){
int i,v,j,n,l;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(l=0;l<n-1;l++){
printf("%d ",a[l]);
}
printf("%d",a[n-1]);
printf("\n");
for(i=1;i<=n-1;i++){
v=a[i];
j=i-1;
while(j>=0 && a[j]>v){
a[j+1]=a[j];
j--;
a[j+1]=v;
}
for(l=0;l<n-1;l++){
printf("%d ",a[l]);
}
printf("%d",a[n-1]);
printf("\n");
}
}

