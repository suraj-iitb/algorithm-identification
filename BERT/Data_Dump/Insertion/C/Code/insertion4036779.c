#include<stdio.h>

void view(int A[] ,int N);
void insertSort(int A[],int N);

int main(){
int A[1000];
int N,i,j;
scanf("%d",&N);
for(i=0;i<N;i++){
    scanf("%d",&A[i]);
     }
view(A,N);
insertSort(A,N);
return 0;
}
void insertSort(int A[],int N){
 int i,j,v;
   for(i=1;i<N;i++){ 
     v = A[i];
     j = i - 1;
   
     while (j >= 0 &&A[j] > v){ 
       A[j+1] = A[j];
       j--;
    A[j+1] = v;
   
     }
        view(A,N);
       }
}

     void view(int A[],int N){
     int i;
     for(i=0;i<N;i++){
          if(i)
           printf(" ");

      printf("%d",A[i]);
      }
      printf("\n");
      }
