
#include <stdio.h>

void selectionSort(int [],int);
void trace(int [],int);

int cnt=0;

int main(){
 int N=0,i,j;
  int A[100];

  scanf("%d",&N);
  for(i=0; i <= N-1; i++){
    scanf("%d",&A[i]);
      }
  selectionSort(A,N);

  return 0;
     }

void Trace(int A[],int N){
  int i;
  for(i=0;i <= N-1;i++){
    printf("%d",A[i]);



    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
   }

void selectionSort(int A[],int N){
  int i,k=0,j=0,minj;
  for(i=0;i<=N-1;i++){
    /*printf("hoge1");*/
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj])minj = j;
	
      /*printf("hoge2");*/


    }
    k=A[i];   A[i] = A[minj];
    A[minj] = k;
    if(i!=minj) cnt++;
  } 
  Trace(A,N);
     }

