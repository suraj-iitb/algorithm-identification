#include <iostream>

using namespace std;

static const int MAX = 100;

void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
}

int selectionSort(int A[], int N){
    int sw = 0;
    for (int i = 0; i < N - 1; i++){
        int minj = i;
        for (int j = i + 1; j < N; j++){
            if (A[j] < A[minj]) minj = j;
        }
        if (i != minj){
            int tmp = A[minj];
            A[minj] =  A[i];
            A[i] = tmp;
            sw++;
        }
    }
    return sw;
}

int main(){
    int A[MAX], num;
    cin >> num;
    for (int i = 0; i < num; i++) cin >> A[i];

    int count = selectionSort(A, num);

    trace(A, num);
    cout << count << endl;

    return 0;
}
