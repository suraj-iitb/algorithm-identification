#include<stdio.h>
int main(){
  int n,i,j,min,a[100],b=0,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++)if(a[j]<a[min])min=j;
    if(i!=min){
      c=a[i];
      a[i]=a[min];
      a[min]=c;
      b++;
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",b);
  return 0;
}
