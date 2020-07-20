#include <stdlib.h>
#include <stdio.h>

int main(){
int k,x,n,i,j,a[100];
k=0;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
        if(a[j]<a[j-1]){
            x=a[j];
         a[j]=a[j-1];
       a[j-1]=x;
          k++;
          }
      }
  }
for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
    }
  printf("%d\n%d\n",a[n-1],k);
return 0;
}
