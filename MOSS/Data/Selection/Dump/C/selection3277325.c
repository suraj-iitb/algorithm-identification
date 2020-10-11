#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a,n,i,j,kari,kazu=0,min;

  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(a[min]>a[j])	min=j;
    }

    if(a[min]!=a[i]){
      kari=a[min];
      a[min]=a[i];
      a[i]=kari;
      kazu++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }

  printf("\n%d\n",kazu);

  return 0;
}
	

