#include <stdio.h>
#include <stdlib.h>

main(){
  int *a;
  int i,j,n,tmp,minj;
  int kokan=0;

  scanf("%d", &n);
  a=(int*)malloc(n*sizeof(int));

  for(i=0; i<n; i++) scanf("%d",a+i);

  //selection sort
  for(i=0; i<=n-1; i++){
    minj = i;
    for(j=i; j<=n-1; j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(minj!=i){
      kokan++;
      //swap
      tmp = a[i];
      a[i]=a[minj];
      a[minj]=tmp;
    }
  }
  //print
  for(i=0; i<n-1; i++)printf("%d ", a[i]);
  printf("%d\n%d\n", a[i], kokan);

  return 0;
}
