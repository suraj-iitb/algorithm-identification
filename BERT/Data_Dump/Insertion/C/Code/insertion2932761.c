#include<stdio.h>
#define MAX 100
void insertionSort(int*,int);
int main(){
  int N;
  int i;
  int point[MAX];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&point[i]);
  }
  
  insertionSort(point,N);

  return 0;
}

void insertionSort(int *point,int N){
  int i;
  int j;
  int l;
  int key;

  for(i=0;i<N;i++){
    if(i!=N-1){
      printf("%d ",point[i]);
    }
    else{
      printf("%d",point[i]);
    }
  }
  printf("\n");
  for(i=1;i<=N-1;i++){
    key=point[i];
    j=i-1;
    while(j>=0 && point[j]>key){
      point[j+1]=point[j];
      j--;
      point[j+1]=key;
    }
    for(l=0;l<N;l++){
      if(l!=N-1){
	printf("%d ",point[l]);
      }
      else{
	printf("%d",point[l]);
      }
    }
    printf("\n");
  }
}

