#include<stdio.h>
#define N 100
int main()
{
  int a[N],i,j,n,b,c=0,d=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    b=a[i];
    for(j=i+1;j<n;j++){
      if(b>a[j]){
	b=a[j];
	c=j;
      }
    }
    if(a[i]!=b){
    a[c]=a[i];
    a[i]=b;
    d++;
    }
  }
  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],d);
  return 0;
}
  
    
	

