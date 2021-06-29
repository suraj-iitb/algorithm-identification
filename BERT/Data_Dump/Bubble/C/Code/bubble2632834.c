#include <stdio.h>
void swap(int *,int *);
void bubbleSort(int [],int);
 
int count=0;
 
int main(){
  int i,n,A[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
    bubbleSort(A,n);
    for(i=0;i<n;i++){
      if(i)printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
  }
 
void swap(int *a,int *b){
  int v;
  v=*a;
  *a=*b;
  *b=v;
}
 
 
void bubbleSort(int A[],int N){
  int i,j,flag;
  int h;
  flag=1;
  i=0;
 
for(h=0;h<=N-1;h++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        swap(&A[j],&A[j-1]);
        count++;
        flag=1;
      }
    }
  i++;
  }
 }
