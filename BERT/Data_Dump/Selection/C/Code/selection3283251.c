#include<stdio.h>

int main(){
  int i,j,n,num=0,v;
  int a[100],minj;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }

    if(i!=minj)
      num++;
      v=a[i];
      a[i]=a[minj];
      a[minj]=v;
  }

  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",num);

  return 0;
}


	

