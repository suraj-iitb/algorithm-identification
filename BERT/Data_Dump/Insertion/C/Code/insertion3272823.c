#include<stdio.h>
static int N=1000;
void irekae(int A[],int n){
   int i;
    for(i=0;i<n;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
 }
int main(){
  int a,n,i,j,A[N];
 scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  irekae(A,n);
  for(j=1;j<n;j++){
     a=A[j];
     i=j-1;
    while(i>=0&&A[i]>a){
      A[i+1]=A[i];
      i=i-1;
    }
    A[i+1]=a;
    irekae(A,n);
  }
  return 0;
}

