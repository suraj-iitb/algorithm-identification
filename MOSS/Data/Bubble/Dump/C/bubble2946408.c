#include<stdio.h>
int main(){

  int c,i,j,n,a[100],count=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j-1]>a[j]){
	c=a[j];
	a[j]=a[j-1];
	a[j-1]=c;
	count++;
      }
    }
  }

for(i=0;i<n;i++){
  if(n-1>i)printf("%d ",a[i]);
  else printf("%d",a[i]);
   }
        printf("\n%d\n",count);
  
    
  return 0;
}

