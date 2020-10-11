#include <stdio.h>

int main(){
  int i,j,n,minj,temp,a[100],sw=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<=n-1;i++){
    minj=i;

    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj])minj=j;
    }

    temp=a[i];
    a[i]=a[minj];
    a[minj]=temp;
    if(i!=minj)sw++;
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }

  printf("\n%d\n",sw);

  return 0;
}

