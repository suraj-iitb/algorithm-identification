#include<stdio.h>
#define N 100
int main(){
  int i,j,a[N],v,n,m;
  
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<m-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[m-1]);

  for(i=1;i<=m-1;i++){
    v=a[i];
    j=i-1;
    while (j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;  
    }
   
    for(n=0;n<m-1;n++){
      printf("%d ",a[n]);
    }
    printf("%d\n",a[m-1]);
  }
  
  
  return 0;
  
}
