#include<stdio.h>
#define N 100

int main(){
  int n,i,j,a[N];
  int tmp,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	count++;
      }
    }
  }
  printf("%d",a[0]);
  for(i=1;i<n;i++){
    printf(" %d",a[i]);
  } 
      
  printf("\n");
  printf("%d\n",count);
  return 0;
}
