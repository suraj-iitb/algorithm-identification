#include <stdio.h>
#define N 100
int main(void){
  int i,j,v,n,m,x,t;
  int a[N];
  scanf("%d",&n);
  m=0;
  while(m<n){
    scanf("%d",&a[m]);
    m++;
  }
  i=1;
  while(i<n){
    for(v=0;v<n-1;v++){
      printf("%d ",a[v]);
    }
    printf("%d\n",a[n-1]);
    t=a[i];
    j=i;
    i++;
    while(j>0&&a[j-1]>t){
      a[j]=a[j-1];
      j--;
    }
    a[j]=t;
  }
  x=0;
  while(x<n-1){
    printf("%d ",a[x]);
    x++;
  }
  printf("%d\n",a[n-1]);
  return 0;
}
