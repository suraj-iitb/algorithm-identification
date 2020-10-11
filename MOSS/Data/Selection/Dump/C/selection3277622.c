#include<stdio.h>
#define A 100


int main(){
  int i,j,tmp,minj,n,a[A],sw=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]) minj=j;
      }
	tmp=a[i];
	a[i]=a[minj];
	a[minj]=tmp;
	if(i!=minj) sw++;
    }

  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],sw);
  

  
  return 0;
}

