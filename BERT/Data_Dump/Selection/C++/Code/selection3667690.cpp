#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int A[100];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        int minj = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (i != minj){
            int v = A[i];
            A[i] = A[minj];
            A[minj] = v;
            cnt++;
        }
    }
    for (int i = 0; i < n; i++){
        if (i == n-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
    cout << cnt << endl;
    return 0;
}
