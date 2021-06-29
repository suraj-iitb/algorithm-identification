#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 150

void trace(int *A, int n){
    for(int i=0;i<n;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    putchar('\n');
}

void bubbleSort(int *A, int n){
   int flag = 1;
   int counter=0;
   int a;
   int i=0;
   while(flag){
       flag = 0;
       for(int j=n-1;j>i;j--){
           if(A[j] < A[j-1]){
               a = A[j];
               A[j] = A[j-1];
               A[j-1] = a;
               flag = 1;
               counter +=1;
           }
        }
        i++;
    }
    trace(A,n);
    printf("%d\n",counter);
   
}
int main(){
    int n;
    int A[MAX];
    

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    bubbleSort(A,n);
    return 0;
    
}
