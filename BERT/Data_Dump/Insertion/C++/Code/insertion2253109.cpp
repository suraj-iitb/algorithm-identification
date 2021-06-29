#include <stdio.h>
#define N 100

int main()
{
  int a[N];
  int k,b,v,i,j,n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<n;i++){
    v = a[i];
    j = i - 1;
      for(b=0;b<n-1;b++){
	printf("%d ",a[b]);
      }
      printf("%d\n",a[b]);
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
  }
  for(b=0;b<n-1;b++){
    printf("%d ",a[b]);
  }
  printf("%d\n",a[b]);
  
  return 0;
}
