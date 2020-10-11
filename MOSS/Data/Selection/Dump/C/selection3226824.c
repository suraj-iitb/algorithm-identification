#include <stdio.h>

int main(){

int n,i,j,t,k,s,minj;
t=0;
scanf("%d\n ",&n);

int a[n];

for(i=0;i<n;i++){
  scanf("%d",&a[i]);
}

for(i=0;i<n;i++){
 minj=i;
  for(j=i;j<n;j++){
   if(a[minj]>a[j]){
    minj=j;
    }
   }
  if(i != minj){
  s=a[i];
  a[i]=a[minj];
  a[minj]=s;
  t++;
  }
}

for(k=0;k<n-1;k++){
  printf("%d ",a[k]);
 }
printf("%d\n",a[n-1]);
printf("%d\n",t);

return 0;
}

