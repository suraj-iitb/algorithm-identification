#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int a[n];
  int i,j,p,count=0;
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    for(j=n-1;j>=i;j--){
      if (a[j]<a[j-1]){
	p=a[j];
	a[j]=a[j-1];
	a[j-1]=p;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
    if(i==n-1) printf("\n");
  }
  printf("%d\n",count);
  return 0;
}

    
