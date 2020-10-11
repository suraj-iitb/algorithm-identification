#include <stdio.h>
int main(){
  int n,a[100],i,count=0,flag=1,tmp,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  while(flag){
    flag=0;

    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]) {
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	flag=1;
	count++;
      }
    }

    
  }

  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }

  printf("%d\n",count);
  return 0;
}
