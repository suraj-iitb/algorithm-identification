#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a,i,j,n,key;

  scanf("%d",&n);
  a =  malloc( n*sizeof(int));

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) putchar(' ');
  }

  putchar('\n');


  for(j=1;j<n;j++){
    key=a[j];
    i=j-1;

    while( i>=0 && a[i] >key){
      a[i+1]=a[i];
      i-=1;
    }

    a[i+1]=key;

    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i!=n-1) putchar(' ');
    }

    putchar('\n');
  }

  return 0;
}
    

