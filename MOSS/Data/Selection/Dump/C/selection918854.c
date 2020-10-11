#include<stdio.h>
#define N 100
void swap(int *, int *);

int main(void){
  int n, i, j, a[N], mini, c=0;
  scanf("%d", &n);
 for(i=0; i < n; i++) scanf("%d", &a[i]);
  for(i=0; i < n; i++){
    mini = i;
    
    for(j=i; j < n; j++){
      if(a[j] < a[mini]) mini = j;
    }
    
    if(i != mini){
      swap(&a[i], &a[mini]);
      c++;
    }
    printf("%d", a[i]);
    if(i < n-1) printf(" ");  
  }


 printf("\n%d\n", c);
 return 0;
 }

void swap(int *a, int *m){
  int temp;
  temp = *a;
  *a = *m;
  *m= temp;
}
