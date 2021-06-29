#include<stdio.h>

int main(){
  int temp,n,i,j,flag=1,a[100],cnt=0;

  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i]);
  }
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	flag=1;
	cnt++;
      }
    }
    i++;
  }

  for(i=0;i<=n-1;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  
  printf("\n%d\n",cnt);
  
  return 0;
}
