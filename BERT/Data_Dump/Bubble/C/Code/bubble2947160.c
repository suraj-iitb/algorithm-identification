#include <stdio.h>
int main(){
  int n,a[100],cnt=0,j,flag=1,tmp;

  scanf("%d",&n);

  for(j=0;j<n;j++) scanf("%d",&a[j]);

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
  }
  
  for(j=0;j<n-1;j++) printf("%d ",a[j]);

  printf("%d\n%d\n",a[n-1],cnt);

  return 0;
}
