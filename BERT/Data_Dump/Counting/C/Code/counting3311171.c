#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10000
void CountingSort(int *,int *,int , int);

int main(){
  int n,*a,*b,i,max;

  scanf("%d",&n);
  if(n < 1 || 2000000 < n)exit(0);

  a = (int *)malloc((n+1)*sizeof(int));
  b = (int *)malloc((n+1)*sizeof(int));

  scanf("%d",&a[0]);
  max = a[0];
  for(i = 1; i < n; i++){
    scanf("%d",&a[i]);
    if(a[i] < 0 || 10000 < a[i])exit(0);
    if(max < a[i])max = a[i];
  }

  CountingSort(&a[0],&b[0],max,n);

  printf("%d",b[1]);
  for(i = 2; i <= n; i++){
    printf(" %d",b[i]);
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int *a,int *b,int k,int n){
  int i,*c,j;
  
  c = (int *)malloc((k+1)*sizeof(int));
  
  for(i = 0; i <= k; i++){
    c[i] = 0;
  }
  
  for(j = 0; j < n; j++){
    c[a[j]]++;
  }

  for(i = 1; i <= k ; i++){
    c[i] = c[i] + c[i - 1];
    //printf("c[%d] = %d\n",i,c[i]);
  }

  for(j = n-1; 0 <= j; j--){
    b[c[a[j]]] = a[j];
    //printf("b[%d]= %d\n",c[a[j]],b[c[a[j]]]);
    c[a[j]]--;
  }
}

