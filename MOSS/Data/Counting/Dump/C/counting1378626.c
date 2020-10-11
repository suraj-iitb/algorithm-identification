#include <stdio.h>
 
main(){
  static int a[2000001],c[10001],b[2000001],k,n,i;
 
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
   
  k=0;
  for(i=1;i<=n;i++){
    if(a[i]>k) k=a[i];
  }
 
  for(i=0;i<=k;i++){
    c[i]=0;
  }
   
  for(i=1;i<=n;i++){
    c[a[i]]++;
  }
   
  for(i=1;i<=k;i++){
    c[i]=c[i]+c[i-1];
  }
 
  for(i=n;i>0;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
 
  for(i=1;i<=n;i++){
    if(i > 1) printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  return 0;
}
