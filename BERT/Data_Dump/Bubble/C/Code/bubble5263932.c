#include<stdio.h>
void bubblesort(int N,int a[],int *count);
int main(void){
  int N,a[100],count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  bubblesort(N,a,&count);
  for(int i=0;i<N;i++){
    printf("%d",a[i]);
    if(i!=N-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",count);
  return 0;
}
void bubblesort(int N,int a[],int *count){
  int i,k,tmp;
  for(i=0;i<N;i++) {
    for(k=0;k<N-i-1;k++) {
      if(a[k]>a[k+1]) {
	tmp=a[k];
	a[k]=a[k+1];
	a[k+1]=tmp;
	(*count)++;
      }
    }
  }
}

