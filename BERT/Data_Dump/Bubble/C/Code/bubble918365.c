#include<stdio.h>

main(void){
  
  int a[100],N,i,j,tempo,c=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(a[j]<a[j-1]){
	tempo=a[j];
	a[j]=a[j-1];
	a[j-1]=tempo;
	c=c+1;
      }
    }
  }

  for(i=0;i<N;i++){
    if(i==N-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",c);
return 0;
}
