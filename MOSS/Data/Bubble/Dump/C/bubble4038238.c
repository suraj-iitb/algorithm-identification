#include <stdio.h>

int main()
{
 int i,j,a[100],count=0,n,tmp;
 
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",&a[i]);
 for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
        if(a[j]<a[j-1]){
            tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
            count++;
        }
    }
 }
 for(i=0;i<n-1;i++){
     printf("%d ",a[i]);
 }
 printf("%d\n",a[n-1]);
 printf("%d\n",count);
 return 0;
}

