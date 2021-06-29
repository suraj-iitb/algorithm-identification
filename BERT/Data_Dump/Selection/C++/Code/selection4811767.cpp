#include <iostream>
using namespace std;

void S_Sort(int A[],int N){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(A[i],A[minj]);
            cnt++;
        }
    }
    
    for(int i = 0; i < N -1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    
    cout << cnt << endl;
}

int main(void){
    // Your code here!
    int N;
    int A[100];
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    S_Sort(A,N);
}

