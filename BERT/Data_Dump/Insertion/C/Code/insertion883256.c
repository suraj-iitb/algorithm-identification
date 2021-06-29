#include<stdio.h>
int main(void)
{
  int n,key,i,j;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n");
  for(j=1;j<n;j++){
    key=a[j];
    i=j-1;
    while(i>=0 && a[i]>key){
      a[i+1]=a[i];
      i--;
    }
    a[i+1]=key;
    
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if (i+1!=n)
	printf(" ");
    }
  printf("\n");
  }  
  return 0;
}
