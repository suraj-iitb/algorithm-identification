#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,a[101],i,j,kari,kazu=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=1;i<n;i++){
    for(j=n-1;j>i-1;j--){
      if(a[j]<a[j-1]){
	kari=a[j];
	a[j]=a[j-1];
	a[j-1]=kari;
	kazu++;
      }
      
    }
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  
  printf("%d\n",kazu);
  return 0;
}
  

