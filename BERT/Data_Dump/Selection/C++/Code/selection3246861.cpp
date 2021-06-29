#include <iostream>

using namespace std;

void selectionSort(int* A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] <A[minj]){
                minj = j;
            }
        }
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if(A[i] != A[minj]){
            count++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i < N - 1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}

int main(){
    int N;
    int A[1000];
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        A[i] = a;
    }
    selectionSort(A, N);
    return 0;
}
