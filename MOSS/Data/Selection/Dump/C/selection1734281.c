#include<stdio.h>

int main(){
  int i,j,n,m,mini,count=0,a[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[mini]) mini = j;
    }

    if(i!=mini){
      m=a[i];
      a[i]=a[mini];
      a[mini]=m;
      count++;
    }
  }

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}
