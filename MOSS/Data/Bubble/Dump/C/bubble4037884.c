#include<stdio.h>
int main(){
  int a[100],c=0,n,j,i,s;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	s=a[j];
	a[j]=a[j-1];
	a[j-1]=s;
	c++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[n-1],c);
       return 0;
       }

