#include <stdio.h>

main(){
  int i,j,a[100],n,min;
  int k,d=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    min=i;
    for(j=min;j<n;j++){
      if(a[j]<a[min]) min=j;
      if(j==n-1 && a[i]>a[min]){
	k=a[i];
	a[i]=a[min];
	a[min]=k;
	d++;
      }
    }
  }
  
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]); 
  printf("%d\n",d);
  return 0;
}
