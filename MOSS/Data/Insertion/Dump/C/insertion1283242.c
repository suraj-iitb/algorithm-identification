#include <stdio.h>
#define A 1000 

main(){
 int i,j,k,n,a[A];

 scanf("%d",&n);
 for(i=0;i<n;i++)scanf("%d",&a[i]);

 for(i=0;i<n;i++){
   j=i;
   while(j>0 && a[j]<a[j-1]){
     k=a[j-1];
     a[j-1]=a[j];
     a[j]=k;
     j--;
   }
  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j!=n-1)printf(" ");
  }
  printf("\n");
 }
  return 0;
}
