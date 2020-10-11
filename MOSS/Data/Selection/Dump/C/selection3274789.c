#include<stdio.h>
int main(){
  int n,a[100],i,j,x,swap=0,mimj;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    mimj=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[mimj]) mimj=j;
    }
    x=a[i];
    a[i]=a[mimj];
    a[mimj]=x;
    if(i!=mimj)swap++;
  }
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",swap);
  return 0;
}
