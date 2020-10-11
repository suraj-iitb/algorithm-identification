#include<stdio.h>
#include<stdlib.h>

int main(){
  int *a,*b,*c;
  int n,i,j,max=-1;
  scanf("%d",&n);
  a=(int *)malloc((n+1)*sizeof(int));
  b=(int *)malloc((n+1)*sizeof(int));
 
  
  for(i=1;i<n+1;i++){
    scanf("%d",&a[i]);
    if(a[i]>=max)max=a[i]; 
  }
  c=(int *)malloc((max+1)*sizeof(int));
   for(i=0;i<max+1;i++){
     c[i]=0;
   }
   for(j=1;j<=n;j++){
   c[a[j]]++;
   }   
   for(i=1;i<max+1;i++){
     c[i]=c[i]+c[i-1];
   }
   for(j=n;j>=1;j--){
     b[c[a[j]]]=a[j];
     c[a[j]]--;
   }
   for(i=1;i<=n-1;i++){
     printf("%d ",b[i]);
   }
   printf("%d\n",b[i]);
   free(a);
   free(b);
   free(c);
   return 0;
}
     

  

