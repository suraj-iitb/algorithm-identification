#include <stdio.h>

int bubbleSort(int A[100],int N);

void show(int A[100],int N);

int bubbleSort(int A[100],int N){

  int i=0,j,c=0,temp,flag = 1;

    while(flag){
        flag = 0;
         for (j = N - 1; j >i; j-- ) {
            if (A[j - 1] > A[j]) {  
                c++;
                temp = A[j];       
                A[j] = A[j - 1];
                A[j - 1]= temp;
                flag = 1;
            
            }
         }
        i++;
    }

    return c;
}



void show(int A[100],int N){

 int i;

 for(i=0;i<N;i++){
     printf("%d",A[i]);
     if(i+1!=N){
         printf(" ");
     }
 }
 printf("\n");

}

int main(){

    int n,i;
    int a[100];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

   int x;
   x = bubbleSort(a,n);

    show(a,n);

     printf("%d\n",x);
   
return 0;

}
