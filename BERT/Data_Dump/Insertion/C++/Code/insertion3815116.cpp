#include <iostream>
using namespace std;

void insertionSort(int* A, int N){
    for(int i = 0; i < N; i++){
        int temp = A[i];
        int j = i - 1;
        while(j >= 0 and A[j] > temp){
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = temp;
        for(int k = 0; k < N; k++){
            if(k > 0){
                cout << " ";
            }
            cout << A[k];
        }
        cout << endl;
    }
}

int main(){
    int N;
    cin >> N;

    int* A;
    A = new int[N];

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    insertionSort(A, N);

    delete [] A;
    
    return 0;
}

