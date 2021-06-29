#include<stdio.h>
int main(){
  int minj;
  int n,m,i,j,count=0;
  int a[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
	
      }
    }
    if(minj!=i){
      m=a[i];
      a[i]=a[minj];
      a[minj]=m;
      count++;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[i]);
  printf("\n%d\n",count);

  return 0;
}

