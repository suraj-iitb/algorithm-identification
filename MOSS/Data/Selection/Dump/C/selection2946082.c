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
  int minj;
  int flag=0;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
      x=a[i];
      a[i]=a[minj];
      a[minj]=x;
      cont++;
      flag=0;
    }
  }
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],cont);
  return 0;
}

