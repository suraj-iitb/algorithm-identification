#include <iostream>
using namespace std;
int main(void){
    int N,A[101];
    cin >> N;
    int v, j;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(int i = 0; i < N; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for(int k = 0; k < N; k++){
            if(k < N - 1)
                cout << A[k] << " ";
            else
                cout << A[k] << endl;;
        }
    }
    
    return 0;
}

