#include<stdio.h>
#define MAX 100

int n;
int data[MAX];

void data_input(){
  int i;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&data[i]);
}

void print(){
  int i;
  for(i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
}

void insertion_sort(){
  print();
  int i,j;
  for(j = 1; j < n; j++){
    int key = data[j];
    i = j-1;
    while(i >= 0 && data[i] > key){
      data[i+1] = data[i];
      i=i-1;
    }
    data[i+1] = key;
    print();
  }
}

int main(){
  data_input();
  insertion_sort();
  return 0;
}

