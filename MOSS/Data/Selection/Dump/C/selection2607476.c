#include <stdio.h>
 
int main(void){
int n,i,j,m,a[100],t,c;
c = 0;
scanf("%d", &n);
for(i=0;i<n;++i){
scanf("%d", &a[i]);
}
for(i=0;i<n;++i){
m=i;
for (j=i;j<n;++j){
if(a[j]<a[m]) 
m=j;
}
if(m!=i){
t=a[i];
a[i]=a[m];
a[m]=t;
c=c+1;
}
}
for(i=0;i<n;++i){
printf("%d",a[i]);
if(i!=n-1)putchar(' ');
}
putchar('\n');
printf("%d\n",c);
return 0;
}
