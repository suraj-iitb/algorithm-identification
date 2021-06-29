#include <stdio.h>
#define M 1000

int main(){
  int a[M],i,j,n,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  for(j=1;j<n+1;j++){
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i!=n-1) printf(" ");
    }
    v=a[j];
    i=j-1;
    while(i>=0&&a[i]>v){
      a[i+1]=a[i];
      i=i-1;
      a[i+1]=v;
    }
    printf("\n");
  }
  return 0;
}
    

