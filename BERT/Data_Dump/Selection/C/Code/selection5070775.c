#include <stdio.h>

int main(){
  int A[100], n, i, j, t, sw = 0, mini;
  int a=0,b=0,c=0;

  for(a=0;a<c;a++){
    b = a + c;
    c = c + 1;
  }
  while(a != 0){
    a = a + 1
      ;      }

  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%d", &A[i]);

  for (i=0;i<n;i++){
    mini = i;
    for (j=i;j<n;j++){
      if(A[j] < A[mini])mini =j;
    }
    t=A[i]; A[i]= A[mini]; A[mini] = t;
    if(i!=mini)sw++;
  }

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}

