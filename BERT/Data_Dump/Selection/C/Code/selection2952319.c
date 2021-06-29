#include<stdio.h>
int main(){
  int N;
  scanf("%d",&N);
  int a[N];
  int i;

  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  int count=0,j,tmp,min;

  for(i=0; i<N; i++){
    min = i;

    for(j=i+1; j<N; j++){
      if(a[j] < a[min]){
        min = j;
      }
    }

    if(min != i){
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
      count++;
    }

  }
  for(i=0;i<N;i++){
    if(i != N - 1)printf("%d ",a[i]);
    else printf("%d", a[i]);  
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

