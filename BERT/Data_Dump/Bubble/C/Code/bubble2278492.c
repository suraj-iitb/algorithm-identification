#include <stdio.h>

int main(){
  int n,i,j,min,tmp,num,a[100];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
	num++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }

  printf("%d\n",num);
  return 0;
}
