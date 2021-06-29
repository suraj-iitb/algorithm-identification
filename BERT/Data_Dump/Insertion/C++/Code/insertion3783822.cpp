#include <iostream>
using namespace std;

int num[100];

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout << num[i];
        if(i!=n-1) cout << " ";
    }
    cout << "\n";
}

void insertionSort(int A[], int n){
    int v, j;
    for(int i=0; i<n; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printArray(A, n);
    }
}

int main(){
    int N;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num[i];
    }

    insertionSort(num, N);

    return 0;
}

