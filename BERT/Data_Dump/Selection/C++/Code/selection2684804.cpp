#include<iostream>
using namespace std;

void printArray(int A[], int N) {
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i == N-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
}

void selectionSort(int A[], int N){
    int i, j, minj, count = 0;
    for(i=0; i<N; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) count++;
    }
    // print array
    printArray(A, N);
    cout << count << endl;
}


int main(void){
    int A[102];
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    selectionSort(A, N);
    return 0;
}
