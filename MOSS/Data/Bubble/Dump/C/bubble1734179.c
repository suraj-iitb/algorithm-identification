#include<stdio.h>

int main(){
  int a[100],i,j,n,m,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){

      if(a[j]<a[j-1]){
	m=a[j];
	a[j]=a[j-1];
	a[j-1]=m;
	count++;
      }

    }
  }

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
