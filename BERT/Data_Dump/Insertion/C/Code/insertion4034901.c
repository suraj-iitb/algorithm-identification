#include<stdlib.h>
#define A 1001
int main(){
  int n,a[A],i,j,x,v;
  scanf("%d",&n);
  if(n>101 || n<0)exit(1);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<=n;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(x=1;x<=n;x++){
      if(x!=n){printf("%d ",a[x]);}
      else printf("%d",a[x]);
    }
    printf("\n");
  }
  
  
  return 0;
}
  
