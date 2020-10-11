#include <stdio.h>

int main()
{
  int N,i,j,tmp,swap_times=0;

  scanf("%d",&N);

  int a[N];

  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<N;i++){
    for(j=(N-1);j>i;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	swap_times++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",a[i]);
    if(i!=N-1) printf(" ");
  }

  printf("\n%d\n",swap_times);

  return 0;
}
