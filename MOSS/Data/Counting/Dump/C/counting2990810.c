#include<stdio.h>
//int A[MAX];
#define MAX 2000001
#define VMAX 10000
void Countingsort(int[],int);
void Countingsort(int A[],int n){
  int i,j,k=0;

  int C[VMAX];
  for(i=0;i<VMAX;i++){
    C[i]=0;
  }
  for(i=0;i<n;i++){
    C[A[i]]++;
  }
  for(i=0;i<VMAX;i++){
    for(j=C[i];j>0;j--){
A[k++]=i;
    }

}
}
int main(){
  int n,i;
  int A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  Countingsort(A,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
  }

}

printf("\n");
return 0;
}

