#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

void trace(int *A, int n){
    for(int i=0;i<n;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    putchar('\n');
}


void insertionSort(int *A, int n){
    int v =0;
    int j =0;
    trace(A,n);
    for (int i=1;i<n;i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }    
        A[j+1] = v;
        trace(A,n);
    }
}
int main(){
    int A[150];
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&A[i]);
    }
    insertionSort(A,n);
    return 0;
}
