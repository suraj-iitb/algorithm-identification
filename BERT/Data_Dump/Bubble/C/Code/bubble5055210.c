#include<stdio.h>
void swap(int *,int *);
int main(){
  int N,a[100],b=0,i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&a[i]);
  for(i=0;i<N;i++)
    for(j=N-1;j>i;j--)
      if(a[j]<a[j-1]){
        swap(&a[j],&a[j-1]);
        b++;
      }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",b);
  return 0;
}

void swap(int *a, int *b){
  int c;
  c=*a;
  *a=*b;
  *b=c;
}
