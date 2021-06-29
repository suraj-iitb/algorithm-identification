#include <stdio.h>
#define N 100
int main(){
  int i,j,k,n,s=0,flag=1,a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  while(flag){
    i=0;
    flag=0;
      for(j=n-1;j>i;j--){
        if(a[j]<a[j-1]){
          k=a[j];
          a[j]=a[j-1];
          a[j-1]=k;
          flag=1;
          s++;
        }
      }
    i++;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[i],s);
  return 0;
}
