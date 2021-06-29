#include <iostream>

using namespace std;

void print(int *data, int N){
    
    cout << data[0];
    for(int i = 1; i < N; i++){
        cout << " " << data[i];
    }
    cout << endl;
    return;
}

int main(){
    int N, A[1000];
    
    // input
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(int i = 1; i < N ; i++){
        int v = A[i];
        int j = i - 1;
        print(A, N);
        while( (j >= 0) && (A[j] > v) ){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
    }
    print(A, N);
    
    return 0;

}
