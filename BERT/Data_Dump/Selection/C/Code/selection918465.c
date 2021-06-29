#include<stdio.h>

main(void){
   
  int N,a[100],i,j,tempo,c=0,mini;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<=N-1;i++){
    mini=i;
    for(j=i;j<=N-1;j++){
      if(a[j]<a[mini]){
	mini=j;
      }
    }
	tempo=a[i];
	a[i]=a[mini];
	a[mini]=tempo;
	if(a[i]!=a[mini])c=c+1;
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d\n",a[i]);
    }
    else printf("%d ",a[i]);
  }
  printf("%d\n",c);
  return 0;
}
