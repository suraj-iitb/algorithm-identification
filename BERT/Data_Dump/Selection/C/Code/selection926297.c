#include<stdio.h>
#define N 100

void swap(int *, int *);
 
int main(void){

  int i,j,n,a[N],m,c=0;

  scanf("%d", &n);

 for(i=0; i < n; i++){
 scanf("%d", &a[i]);
}
  for(i=0; i < n; i++){
    m = i;
     
    for(j=i; j < n; j++){
      if(a[j] < a[m]) m = j;
    }
     
    if(i != m){
      swap(&a[i], &a[m]);
      c++;
    }
    printf("%d", a[i]);
    if(i < n-1) printf(" ");  
  }
 
 
 printf("\n%d\n", c);
 return 0;

 }
 
void swap(int *a, int *b){

  int temp;

  temp = *a;
  *a = *b;
  *b= temp;
}
