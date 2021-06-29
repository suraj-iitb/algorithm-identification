#include<stdio.h>
#define N 100

void draw(int, int *);

int main(){

  int n, a[N], v;
  int i, j;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  } 

  draw(n, a);

  for(i = 1; i < n; i++){

    v = a[i];
    j = i - 1;

    while(j >= 0 && a[j] > v){
      a[j + 1] = a[j];
      j--;

    }

    a[j + 1] = v;

    draw(n, a);

  }

  return 0;
}

void draw(int n, int *a){

  int i;

  for(i = 0; i < n; i++){
    printf("%d",a[i]);

    if(i != n - 1) printf(" ");

  }
 
  printf("\n");
  
}
