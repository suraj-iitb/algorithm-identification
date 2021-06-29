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

int selectionSort(int A[], int N) {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        int minj = i;
        for(int j=i+1; j<N; j++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        if(i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    return cnt;
} 

int main(){
    int N, cnt;
    cin >> N;
    int A[N];
    for (int i=0; i < N; i++) {
        cin >> A[i]; 
    }
    cnt = selectionSort(A, N);
    trace(A, N);
    cout << cnt << endl;
    return 0;
}
