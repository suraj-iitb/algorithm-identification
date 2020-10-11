#include <stdio.h>
#include <stdlib.h>

int CountSwap=0;

void swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
  CountSwap++;
}

void SelectionSort(int list[],int num){
  int i,j,min,key;
  for(i=0;i<num;i++){
    min=list[i];key=i;
    //i+1~num-1?????§????????¢??¢?´¢???????°???????????????????
    for(j=i+1;j<num;j++){
      if(list[j]<min){min=list[j];key=j;}
    }
    if(i!=key)swap(&list[i],&list[key]);
  }
}

int main(void){
  int N,i;
  scanf("%d",&N);

  int* list=(int*)malloc(sizeof(int)*N);
  if(list==NULL)exit(0);

  for(i=0;i<N;i++)scanf("%d",&list[i]);

  SelectionSort(list,N);
  for(i=0;i<N-1;i++)printf("%d ",list[i]);
  printf("%d\n%d\n",list[N-1],CountSwap);

  free(list);
  return 0;
}
