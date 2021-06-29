#include <stdio.h>

int main(){
  int n,i,j,min,tmp,num=0,a[100];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]) min=j;
    }
      tmp=a[i];
      a[i]=a[min];
      a[min]=tmp;
      if(i!=min) num++;
  }

  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",a[i]);
    else printf("%d\n",a[n-1]);
  }

  printf("%d\n",num);
  return 0;
}
