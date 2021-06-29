#include <stdio.h>
int main(){
  int n,a[100],min,i,count=0,tmp,j,flag;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
 

  for(i=0;i<n;i++){
    min=i;
    flag=0;
    for(j=i+1;j<n;j++){
      if(a[j]<a[min]){
	min=j;
	flag=1;
      }
    }
	tmp=a[i];
	a[i]=a[min];
	a[min]=tmp;
	if(flag==1)count++;
      
    }
    
  


  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }

  printf("%d\n",count);

  return 0;
}
