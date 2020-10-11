#include<stdio.h>
#define N 100
main(){
  int i,j,count=0,mini,n,a,A[N],f;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < n; i++){
    mini = i;
    f = 0;
    for(j = i; j < n; j++){
      if(A[j] < A[mini]){
        mini = j;
	f = 1;
      }
    }
    if(f == 1){
	a = A[i];
	A[i] = A[mini];
	A[mini] = a;
        count++;
    }
  }
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
