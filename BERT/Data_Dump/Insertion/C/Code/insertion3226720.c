#include <stdio.h>

int main(){

int n,i,j,s,k;

scanf("%d\n ",&n);

int a[n];
 k=n;

for(i=0;i<n;i++){
  scanf("%d ",&a[i]);
}

 for(k=0;k<n-1;k++){
  printf("%d ",a[k]);
 }
printf("%d\n",a[n-1]);


for(i=1;i<n;i++){

  j=i-1;
  s=a[i];
   while(j>=0 && a[j]>s){

     a[j+1]=a[j];
     a[j]=s; 
     j--;
   }
  for(k=0;k<n-1;k++){
  printf("%d ",a[k]);
 }
printf("%d\n",a[n-1]);

}

return 0;
}








