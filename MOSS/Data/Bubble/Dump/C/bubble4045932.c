#include<stdio.h>

int main(){
  int a[100],flag,j,n,cnt=0,temp;

  scanf("%d",&n);

  for(j=0;j<n;j++){
    scanf("%d",&a[j]);
  }

  flag=1;

  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	flag=1;
	cnt++;
      }
    }
  }
      
  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j!=n-1)printf(" ");
  }

  printf("\n%d\n",cnt);

  return 0;
}
  
  

