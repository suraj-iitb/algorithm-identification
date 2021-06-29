#include <stdio.h>
#define N 100

int main(){
  int a[N],i,j,minj,b,n,count;
  scanf("%d",&n);
  if(n>100){
    printf("Cannot\n");
    return 0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]<0||a[i]>100) return 0;
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    b=a[i];
    a[i]=a[minj];
    a[minj]=b;
    if(a[i]!=a[minj]) count++;
  }

  printf("%d",a[0]);
  for(i=1;i<n;i++) printf(" %d",a[i]);
  printf("\n%d\n",count);

  return 0;
}

