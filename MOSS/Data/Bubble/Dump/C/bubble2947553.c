#include <stdio.h>
#define SWAP(type,a,b) { type temp = a; a = b; b = temp; }
#define N 100

int main(){
  int i, j, cont=0, n;
  int a[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j] < a[j-1]){
	SWAP(int,a[j],a[j-1]);
      cont++;
      }
    }
  }


  for(i=0;i<n;i++){
    if (i!=0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cont);
  return 0;
}
  

