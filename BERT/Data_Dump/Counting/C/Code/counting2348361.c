#include<stdio.h>
#include <stdlib.h>

int main(){
  int  i = 0, n, c[10001],j;
  int *a,*b;
  scanf("%d",&n);
  a = malloc(sizeof(int)*n+1);
  b = malloc(sizeof(int)*n+1);
  
 for(i = 0; i < 10001; i++){
    c[i] = 0;
  }

 for(i = 0; i < n; i++){
    scanf("%d",&a[i+1]);
    c[a[i+1]]++;
 }

 for(i = 1; i < 10001; i++){
   c[i] = c[i] + c[i - 1];
 }
 for(j = 1;j < n+1; j++){
  b[c[a[j]]] = a[j];
    c[a[j]]--;
 }

 for ( i =1; i < n; i++){
    printf("%d ",b[i]);
 }
 printf("%d\n",b[i]);
       return 0;
}
