#include <stdio.h>
#include <stdlib.h>

main(){
  int *a;
  int n,i,j,tmp,flag;
  int kokan=0;

  scanf("%d", &n);
  a = (int*)malloc(n*sizeof(int));

  for(i=0; i<n; i++) scanf("%d", a+i);

  //bubbleSort
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(a[j]<a[j-1]){
	kokan++;
	//swap
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
      }
    }
  }
  //print
  for(i=0; i<n-1; i++) printf("%d ", a[i]);
  printf("%d\n%d\n", a[i], kokan);

  return 0;
}
