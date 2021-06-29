#include<stdio.h>
#define N 10000

main(){

  int n,m,i,j,a[N],b[N],c=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&m);

  for(j=0;j<m;j++){
    scanf("%d",&b[j]);
  }


 for(i=0;i<m;i++){ 
   for(j=0;j<n;j++){

     if(b[i]==a[j]){ c++;
     break;
     }
   }
 }

 printf("%d\n",c);
 return 0;
}
