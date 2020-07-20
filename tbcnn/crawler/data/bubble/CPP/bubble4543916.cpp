#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){
    int t = 0;
    bool flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = N - 1; j >= i + 1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                t++;
            }
        }
    }
    return t;
}

int main(){
    int A[100], N, t;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    t = bubbleSort(A, N);
    
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    
    cout << endl << t << endl;
    
    return 0;
    
}
