#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N; 
    int X[N];
    for (int i = 0; i < N; i++){
        cin >> X[i]; 
    } 

    for (int i = 0; i < N - 1; i++) cout << X[i] << ' ';
    cout << X[N - 1] << endl;
    for (int i = 1; i < N; i++){ // 比較は植木算
        int j, v = X[i];
        for (j = i; j > 0; j--){
            if (v > X[j - 1]){
                break;   
            }
            X[j] = X[j - 1];
        }
        X[j] = v;
        for (int j = 0; j < N - 1; j++) cout << X[j] << ' ';
        cout << X[N - 1] << endl;
    } 
 }

