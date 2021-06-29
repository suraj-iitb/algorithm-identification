#include<stdio.h>
int main(){
  int flag=1;
  int n,m,i,j,count=0;
  int a[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	m=a[j];
	a[j]=a[j-1];
	a[j-1]=m;
	flag=1;
	count++;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[i]);
  printf("\n%d\n",count);

  return 0;
}

