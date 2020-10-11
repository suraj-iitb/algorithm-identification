#include <stdio.h>
#include <stdlib.h>
#define N 100000
 
int Partition(int, int);
void Quicksort(int, int);

typedef struct{
  int n;
  char c;
  int count;
}Card;

Card a[N];

int main(void){
  int n,i,q,flag=0;
  char y;

  scanf("%d%c",&n,&y);
  for(i = 1; i < n+1; i++){
    scanf("%c%d%c",&a[i].c, &a[i].n, &y);
    a[i].count = i;
  }

  Quicksort(1,n);

  for(i = 0; i < n; i++){
    if(a[i].n == a[i+1].n && a[i].count > a[i+1].count){
      flag = 1;
      break;
    }
  }

  if(flag == 0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for(i = 1; i < n+1; i++){
    printf("%c %d\n",a[i].c,a[i].n);
  }
  return 0;
}
 
int Partition(int p, int r){
  int i,j;
  Card x,tmp;

  x = a[r];
  i = p - 1;

  for(j = p; j <= r-1; j++){
    if(a[j].n <=  x.n){
      i =  i + 1;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;

  return i+1; 
}

void Quicksort(int p, int r){
  int q;
  if(p < r){
    q = Partition(p,r);
    Quicksort(p,q-1);
    Quicksort(q+1,r);
  }
}
