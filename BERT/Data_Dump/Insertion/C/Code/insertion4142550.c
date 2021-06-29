#include<stdio.h> //挿入ソート
#define N 101

void sort(int *,int);
void output(int * ,int);


int main(){

  int i,n;
  int a[N];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  output(a,n);
  sort(a,n);
  
  return 0;
}


void sort(int A[],int n){

  int i,j,key;
  
  for(i = 1 ; i < n ; i++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key ;

    output(A,n);
  }
}


void output(int A[],int n){
  
  int i;
  
  for(i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

