#include <stdio.h>

int main(){

  int n;
  int B[100];
  int i,j;
  int koukann=0;
  int s;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&B[i]);

  for(i=0;i<n;i++){
    for(j=n-1;j>i-1;j--){
      if(B[j]<B[j-1]) {
	s=B[j-1];
	B[j-1]=B[j];
	B[j]=s;
	koukann++;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%d ",B[i]);

  printf("%d\n",B[n-1]);
  

  printf("%d\n",koukann);


  return 0;
}
