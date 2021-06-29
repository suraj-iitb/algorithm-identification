#include<stdio.h>
int main(){
  int i,j,a[100],n,minj,temp,sum=0;
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
    if(minj!=i){
	temp=a[i];
	a[i]=a[minj];
	a[minj]=temp;
	sum++;
    }
   
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",sum);
  return 0;
}

