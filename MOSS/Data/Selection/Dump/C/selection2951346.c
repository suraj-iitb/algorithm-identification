#include <stdio.h>
#define SWAP(a,b) { int temp = a; a = b; b = temp; }
#define N 100

int main(){
  int minj, n, i, j, cont=0;
  int a[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[minj] > a[j]){
	minj = j;
      }
    }
    
    if(minj != i){
      SWAP(a[i],a[minj]);
      cont++;
    }
  
  }
  

  for(i=0;i<n;i++){
    if (i!=0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cont);
  return 0;
}

