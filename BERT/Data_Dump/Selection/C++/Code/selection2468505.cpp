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

int SelectionSort(int A[], int num){
    int sw = 0;
    int minj;

    for(int i=0; i<num; i++){
        minj = i;
        for(int j=i; j<num; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if (A[i] != A[minj]){
            swap(A[i], A[minj]);
            sw++;
        } 
    }
    return sw;
}

int main(){

    int num;
    int A[100];

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> A[i];
    }

    int sw = SelectionSort(A, num);

    printArray(A, num);

    cout << sw << endl;

    return 0;
}
