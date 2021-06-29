#include<stdio.h>
void insertionSort(int[], int);
int main(){
    int n,i;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
 insertionSort(a,n);
 return 0;
}
void insertionSort(int A[],int N){
    int i,j,v;
    for(j=0;j<N;j++){
      if(j!=0) printf(" ");
      printf("%d",A[j]);
    }
   printf("\n");
     for(i=1;i<N;i++){
    v = A[i];
    j = i - 1;
   while (j >= 0 && A[j] > v){
   A[j+1] = A[j];
     j--;
    A[j+1] = v;
   } 
   for(j=0;j<N;j++){
     if(j!=0) printf(" ");
     printf("%d",A[j]);
   }
     printf("\n");
     }
}

