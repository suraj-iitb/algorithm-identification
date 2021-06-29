#include<stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int i,j;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int x;
  int cont=0;
  int flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
	cont++;
	flag=1;
      }
    }
  }
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],cont);
  return 0;
}

