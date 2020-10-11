#include <stdio.h>

int main(){
  int a[100];
  int i,j,minj,n,alt,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++)
      if(a[minj]>a[j])minj=j;
    if(i!=minj){
      alt=a[i];
      a[i]=a[minj];
      a[minj]=alt;
      count++;
    }
  }
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],count);

  return 0;
}
