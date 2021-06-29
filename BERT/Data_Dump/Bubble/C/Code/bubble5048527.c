#include <stdio.h>

int main(){
  int n,a[100],flag,i,j,x,c=0;
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&a[j]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	c++;
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
      }
    }
  }
  for(j=0;j<n;j++){
    if(j>=1) printf(" ");
    printf("%d",a[j]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
