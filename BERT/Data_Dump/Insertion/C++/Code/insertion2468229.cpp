#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void printArray(int A[], int num){
    for(int j=0; j<num; j++){
        if (j > 0) printf(" ");
        printf("%d", A[j]);
    }
    printf("\n");
}

void insertionSort(int A[], int num){
    int j, i;

    for(i=1; i<num; i++){
        j = i - 1;
        while (j >= 0){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
            }
            j--;
        }
        printArray(A, num);
    }
}

int main(){
   
    int num;
    int A[100];

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> A[i];
    }

    printArray(A, num);

    insertionSort(A, num);

    return 0;
}
