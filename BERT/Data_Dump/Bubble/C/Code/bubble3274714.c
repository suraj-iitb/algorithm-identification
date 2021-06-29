#include<stdio.h>
int main(){
  int flag,j,n,a[100],temp,sum=0;
  flag=1;
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&a[j]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	sum++;
	flag=1;
      }
    }
  }
    for(j=0;j<n;j++){
      if(j==n-1)printf("%d\n",a[j]);
      else printf("%d ",a[j]);
    }
    printf("%d\n",sum);
    return 0;
}
  
      
    

