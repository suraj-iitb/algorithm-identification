#include<stdio.h>
#define N 2000001
 
int a[N],c[N],b[N];
 
int main(){
  int i,j,n,k=0;
    
  scanf("%d",&n);
 
  for(i = 1; i < n+1; i++){
    scanf("%d",&a[i]);
    if(a[i] >k){
      k = a[i];
    }
  }
  for(i = 0; i < k+1; i++){
    c[i] = 0;
  }
  for(j = 1; j < n+1; j++){
    c[a[j]] = c[a[j]] + 1;
  }
 
  for(i = 1; i <= k; i++){
    c[i] = c[i] + c[i-1];
  }
  
  for(j = n; j > 0; j--){
    b[c[a[j]]] = a[j];
    c[a[j]] = c[a[j]] - 1;
  }
 
  for(i = 1; i < n; i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[n]);
 
  return 0;
}

		



