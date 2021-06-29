#include <stdio.h>
#define N 100

int main(){
  //insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
  int n,a[N],i,v,j,c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  // for i が 1 から N-1 まで

  for(i=0;i<n;i++){
    v = a[i];
    j = i - 1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(c=0;c<n;c++){
      printf("%d",a[c]);
      if(c==n-1)break;
      printf(" ");
    }
    printf("\n");
  }


  return 0;
}

