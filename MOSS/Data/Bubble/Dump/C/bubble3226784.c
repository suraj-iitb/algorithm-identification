#include <stdio.h>

int main(){

int n,i,j,s,t,k;
t=0;
scanf("%d\n ",&n);

int a[n];

for(i=0;i<n;i++){
  scanf("%d",&a[i]);
}

 for(k=0;k<n-1;k++){
 j=n-1;
 while(j>0){
  if(a[j]<a[j-1]){
   s=a[j-1];
   a[j-1]=a[j];
   a[j]=s;
  t++;
  }
  j--;
 }
}

for(k=0;k<n-1;k++){
  printf("%d ",a[k]);
 }
printf("%d\n",a[n-1]);
printf("%d\n",t);

return 0;
}
