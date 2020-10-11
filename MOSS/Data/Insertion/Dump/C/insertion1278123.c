#include <stdio.h>

void print(int*,int);
void Insertion_Sort(int*,int);

int main(){
  int N,a[100],i,j,key;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&a[i]);
  }
  print(a,N);
  for(i = 1 ; i < N ; i++){
    key = a[i];
    j = i-1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    print(a,N);
  }
  return 0;
}

void print(int *a,int N){
  int i;
  for(i = 0 ; i < N ; i++){
    printf("%d%c",a[i],i < N-1 ? ' ' : '\n');
  }
}
