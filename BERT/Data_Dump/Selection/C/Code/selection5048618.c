#include <stdio.h>

int main(){
  int x,n,a[100],i,j,c=0,minj;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(a[i]!=a[minj]){
    c++;
    x=a[i];
    a[i]=a[minj];
    a[minj]=x;
    }
  }
  for(i=0;i<n;i++){
    if(i>=1) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
