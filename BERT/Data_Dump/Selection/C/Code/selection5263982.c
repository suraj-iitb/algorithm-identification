#include<stdio.h>
void SelectionSort(int N,int a[],int *count);
int main(void){
  int N,a[100],count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  SelectionSort(N,a,&count);
  for(int i=0;i<N;i++){
    printf("%d",a[i]);
    if(i!=N-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",count);
  return 0;
}
void SelectionSort(int N,int a[],int *count){
  int min,minj,tmp;
  for(int i=0;i<N;i++){
    minj=i; min=a[i];
    for(int j=i+1;j<N;j++){
      if(a[j]<min){
	min=a[j]; minj=j;
      }
    }
    if(i!=minj){
      tmp=a[i];
      a[i]=a[minj];
      a[minj]=tmp;
      (*count)++;
    }
  }
}

