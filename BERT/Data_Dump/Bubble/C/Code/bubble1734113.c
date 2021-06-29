#include <stdio.h>
int main(){
  int N,i,j,temp,c=0;
  int a[100];

  scanf("%d",&N);
  
  for(i = 0;i < N;i++) scanf("%d",&a[i]);

  for(i = 0;i < N-1;i++){
    for(j = N-1; j != 0; j--){
      if(a[j]<a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	c++;
      }
    }
  }

  for(i = 0;i < N-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[N-1]);
    

  printf("\n%d\n",c);

  return 0;
}
