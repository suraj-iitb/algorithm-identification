#include <iostream>
#include <algorithm>
using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++){
        if (i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void bubbleSort(int A[], int N){
    int flag = 1;
    int cnt = 0;
    int tmp;
    for(int i=0;flag;i++){
        flag = 0;
        for(int j= N-1; j >= i+1; j--){
            if (A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    trace(A, N);
    cout << cnt << endl;
} 

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i < N; i++) {
        cin >> A[i]; 
    }
    bubbleSort(A, N);
    return 0;
}
