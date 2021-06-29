#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 150
void trace(int *A, int n){
    for(int i=0;i<n;i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    putchar('\n');
}


void selectionSort(int *A, int n){
    int minj;
    int counter=0;
    for(int i=0;i<n;i++){
        minj = i;
        for(int j=i;j<n;j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        if(minj !=i){
        swap(A[minj],A[i]);
        counter++;
        }
    }
    trace(A,n);
    printf("%d\n",counter);
}

int main(){
    int n;
    int A[150];

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    selectionSort(A,n);
    return 0;
}
