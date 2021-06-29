#include <stdio.h>

int main(){
  int n,a[100],i,k,j,key;
  scanf("%d",&n);
 
  for(i=0;i<n;i++) scanf("%d",&a[i]);
 for(i=0;i<n-1;i++) printf("%d ",a[i]);
 printf("%d\n",a[n-1]);
 for(j=1;j<n;j++){
   key=a[j];
  i=j-1;
  while (i>-1 && a[i]>key){
    a[i+1]=a[i];
i--;
}
  a[i+1]=key;
for(k=0;k<n-1;k++) printf("%d ",a[k]);
 printf("%d\n",a[n-1]);
}

return 0;
}
