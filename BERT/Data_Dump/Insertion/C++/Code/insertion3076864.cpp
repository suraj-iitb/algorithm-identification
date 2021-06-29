#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int A[100];
    for(int i = 0; i < 100; i++){
        A[i] = 0;
    }
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        for(int k = 0; k < N-1; k++){
            cout << A[k] << " ";
        }
        cout << A[N-1] << endl;
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    return 0;
}

