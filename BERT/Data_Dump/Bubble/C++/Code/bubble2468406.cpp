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

int bubbleSort(int A[], int num){
    int sw = 0;
    for(int i=0; i<num-1; i++){
        for(int j=num-1; j>=i+1; j--){
            if (A[j-1] > A[j]){
                swap(A[j-1], A[j]);
                sw++;
            }
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

    int sw = bubbleSort(A, num);

    printArray(A, num);

    cout << sw << endl;

    return 0;
}
