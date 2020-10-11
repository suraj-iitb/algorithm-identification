#include <stdio.h>

int main(){
  int n,i,j,cnt=0,min=0,tmp=0;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]) min=j;
    }
      tmp=a[min];
      a[min]=a[i];
      a[i]=tmp;
      if(i!=min) cnt++;
  }

  for(i=0;i<n;i++){
     printf("%d",a[i]);
     if(i==n-1) printf("\n");
     else printf(" ");
  }
  printf("%d\n",cnt);

  return 0;
}
