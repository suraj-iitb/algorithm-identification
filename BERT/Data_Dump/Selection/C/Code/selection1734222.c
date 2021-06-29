#include <stdio.h>
int main(){
  int N,i,j,c=0,temp,a[100],min;
  
  scanf("%d",&N);
  
  for(i = 0;i < N; i++) scanf("%d",&a[i]);
  
  for(i = 0; i < N-1; i++){
    min = i;
    for(j = i + 1; j < N; j++){
      if(a[min] > a[j]) min = j;
    }

    if(a[i] > a[min]){
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
      c++;
    }

  }

  for(i = 0;i < N-1; i++) printf("%d ",a[i]);
  printf("%d",a[N-1]);

  printf("\n%d\n",c);

  return 0;
}
