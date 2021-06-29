#include<stdio.h>

int N,data[100];

void input(){
  scanf("%d",&N);
  int i;
  for(i = 0; i < N; i++) scanf("%d",&data[i]);
}

void print(){
  int i;
  for(i = 0; i < N; i++){
    if(i) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
}

void insertion_sort(){
  print();
  int i,j;
  for(j = 1; j < N; j++){
    int key = data[j];
    i = j-1;
    while(i >= 0 && data[i] > key){
      data[i+1] = data[i];
      i--;
    }
    data[i+1] = key;
    print();
  }
}

int main(){
  input();
  insertion_sort();
  return 0;
}

