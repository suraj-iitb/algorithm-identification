#include<stdio.h>
int main(void)
{
  int n,a[100],i,j,k,tmp;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  for(i=1;i<n;i++){
    k = a[i];
    j=i-1;
    while(j>=0 && k<a[j]){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = k;
    for(j=0;j<n-1;j++){
      printf("%d ",a[j]);
    }
    printf("%d\n",a[n-1]);
  }
  return 0;
}

