#include<stdio.h>

 void bubbleSort(int[],int);

 int main(){
   int A[100];
   int i,n;
   scanf("%d",&n);
   if(n>=1&&n<=100){

     for(i=0;i<n;i++){
       scanf("%d",&A[i]);
     }
   bubbleSort(A,n);
   }
 }

void bubbleSort(int A[],int n){
  int num;
  int count=0;
  int j,i,k;

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){  
      if(A[j]<A[j-1]){
        num=A[j-1];
        A[j-1]=A[j];
        A[j]=num;
        count++; 
      }
    }
  }
  for(k=0;k<n;k++){
    printf("%d",A[k]);
     if(k<n-1)printf(" ");
    }
    printf("\n");
  printf("%d\n",count);
}

