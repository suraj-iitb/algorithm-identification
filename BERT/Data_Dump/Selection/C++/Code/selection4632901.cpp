#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int x = 0;
    for(int i = 0; i < N - 1; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj] > A[j]) minj = j;
        }
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if(minj != i) x++;
    }
    
    for(int i = 0; i < N; i++){
        cout << A[i] << ((i == N -1) ? "\n" : " " );
    }
    cout << x << endl;
}
