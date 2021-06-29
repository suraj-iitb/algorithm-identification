#include <stdio.h>
#define N 100

int main(){

  int a[N];
  int n,i,j;
  int min,temp,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){
        min=j;
      }
      }
      if(i!=min){
        temp=a[i];
      a[i]=a[min];
      a[min]=temp;
      count++;
    }
  }

    for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",count);

    return 0;

  }
