#include <stdio.h>

main(){
  int i,j,a[100],n;
  int flag=1,k,d=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	k=a[i-1];
	a[i-1]=a[i];
	a[i]=k;
	flag++;
      }
    }
      d+=flag;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]); 
  printf("%d\n",d);
  return 0;
}
