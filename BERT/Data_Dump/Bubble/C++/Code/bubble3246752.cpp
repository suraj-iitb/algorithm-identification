#include <iostream>

using namespace std;

void bubbleSort(int* A, int N){
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int j = N - 1; j > 0; j--){
            if(A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                count++;
            }
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
    bubbleSort(A, N);
    return 0;
}
