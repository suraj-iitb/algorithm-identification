#include<iostream>
using namespace std;

int bubbleSort(int A[], int N);
int main(){
    int N, x;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    x = bubbleSort(A, N);
    
    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl << x << endl;
    
    return 0;
}

int bubbleSort(int A[], int N){
    bool flag = 1;
    int x = 0;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = N -1; j >= i + 1; j--){
            if(A[j] < A[j -1]){
                swap(A[j], A[j -1]);
                flag = 1;
                x++;
            }
        }
    }return x;
    
}
