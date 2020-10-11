#include <stdio.h>
#define N 100
int main(){
  int i,j,n,a[N],flag=1,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  i=0;

  while(flag!=0){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        flag=a[j];
	a[j]=a[j-1];
        a[j-1]=flag;
	flag=1;
	count++;
      }
    }
    i++;
  }
  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }
  printf("%d\n",count);
  return 0;
}
