#include<stdio.h>
int main()
{
  int n,i,k,j,st,ex=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int flag=1;
  while(flag==1){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	st=a[j-1];
	a[j-1]=a[j];
	a[j]=st;
	flag=1;
	ex++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
   printf("%d\n",ex);
  return 0;
}
