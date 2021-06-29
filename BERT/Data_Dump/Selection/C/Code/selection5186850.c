#include <stdio.h>
void swap(int*,int*);
int main(){
  int a[100],N,i,min,j,koukan,k=0;
  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&a[i]);
  }
    for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
      if(a[j]<a[min]){
        min=j;
      }
         }
    if(i!=min){
      swap(&a[i],&a[min]);
      k++;
    }
  }
  for(i=0;i<=N-1;i++){
    if(i==N-1) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",k);
  return 0;
    }
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
