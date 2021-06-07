#include <stdio.h>
int search(int *A,int n, int x){
  int i=0;
  A[n]=x;
  while(A[i]!=x) i++;
  return i !=n;
}

int main(int argc, char const *argv[]) {
  /* code */
  int i,n1,n2,sum=0,x;
  int A[10000];

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&x);
    if(search(A,n1,x)) sum++;
  }
  printf("%d\n",sum);
  return 0;
}
