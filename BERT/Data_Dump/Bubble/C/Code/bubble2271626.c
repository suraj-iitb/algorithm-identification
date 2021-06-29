#include <stdio.h>
int main(){
  int flag=1, i,j,n,a[100],work,count=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  
  while(flag){
    flag=0;
    for(j=n-1; j>=1; j--){
      if(a[j] < a[j-1]){
	work=a[j];
	a[j]=a[j-1];
	a[j-1]=work;
	count++;
	flag=1;
      }     
    }
  }
  
  if(n==1) printf("%d",a[0]);
  else{
    for(i=0; i<n; i++){
      if(i==n-1) printf("%d", a[i]);
      else printf("%d ",a[i]);
    }
  }
  printf("\n%d\n",count);
  return 0;
}
