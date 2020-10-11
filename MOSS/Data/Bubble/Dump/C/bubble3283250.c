#include<stdio.h>

int main(){
  int n,a[100],i,j,v;
  int flag=1,num=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n-1;i++){

    for(j=0;j<n-1;j++){
      flag=0;
      if(a[j]>a[j+1]){
	v=a[j+1];
	a[j+1]=a[j];
	a[j]=v;

	flag=1;
      }
      if(flag==1)
	num++;
    }
  }

   for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",num);

  return 0;
}

