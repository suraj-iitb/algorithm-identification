#include <stdio.h>
#include <stdlib.h>
int n;
 int c[10001] = {};

CountingSort(int *a,int *b,int k){
  int i,j;
 
  
  // for(i = 0;i <= k;i++) c[i] = 0;
  
  // printf("\n");
  for(i = 1;i <= k;i++){
    c[i] = c[i] + c[i - 1];
  }

  
  for(j = n;j >= 1;j--){
    // printf("a = %d,b = %d,c = %d\n",a[j],b[c[a[j]]],c[a[j]]);
    b[c[a[j]]] = a[j];
    // printf("a[%d] = %d,b[c[a[%d]]] = %d,c[a[%d]] = %d\n",j,a[j],j,b[c[a[j]]],j,c[a[j]]);
    c[a[j]]--;
  }
}

int main(){
  int i,k = 0;
  int *a,*b;

  scanf("%d",&n);

  a = malloc(sizeof(int) * (n + 1));
  b = malloc(sizeof(int) * (n + 1));

  for(i = 0;i <= n;i++){
    a[i] = 0;
    b[i] = 0;
  }
  
  for(i = 1;i <= n;i++){
    scanf("%d",&a[i]);
    c[a[i]]++;
    if(a[i] > k) k = a[i];
  }
 
  CountingSort(a,b,k);

  for(i = 1;i <= n;i++){
    if(i != n ) printf("%d ",b[i]);
    else printf("%d\n",b[i]);
  }
  return 0;
}
    
    
