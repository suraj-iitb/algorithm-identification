#include <stdio.h>
#define max 2000000
int a[max+1], b[max+1], c[max+1];

int main(){
   
  int n, i, j, k;
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&a[i+1]);
  }
   
  for(i = 0; i < n; i++){ //iの出現回数をカウント
    c[a[i+1]]++;
  }
  for(i = 0; i < max; i++){ //i以下の出現回数カウント
    c[i+1] = c[i+1] + c[i];
  }
  for(i = n; i > 0; i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  for(i = 0; i < n-1; i++){
    printf("%d ",b[i+1]);
  }
  printf("%d\n",b[n]);

  return 0;
}
